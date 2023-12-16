#include "CPeUtil.h"
#include <iostream>
CPeUtil::CPeUtil()
{
	fileBuff = NULL;
	fileSize = 0;
	pDosHeader = NULL;
	pNtHeader = NULL;
	pFileHeader = NULL;
	pOptionHeader = NULL;
}

CPeUtil::~CPeUtil()
{
	if (fileBuff)
	{
		delete[] fileBuff;
		fileBuff = NULL;
	}
}

BOOL CPeUtil::loadFile(const char* fileName)
{
	HANDLE hFile = CreateFileA(fileName, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	
	if ((int)hFile == -1)
	{
		return FALSE;
	}
	
	fileSize = GetFileSize(hFile, 0);
	fileBuff = new char[fileSize];
	DWORD realRead = 0;

	BOOL isSuccess = ReadFile(hFile, fileBuff, fileSize, &realRead, 0);
	CloseHandle(hFile);
	if (!isSuccess)
	{
		return FALSE;
	}

	if (initPeInfo())
	{
		return TRUE;
	}

	return FALSE;
}

BOOL CPeUtil::initPeInfo()
{
	pDosHeader = (PIMAGE_DOS_HEADER)fileBuff;

	if (pDosHeader->e_magic != IMAGE_DOS_SIGNATURE)
	{
		return FALSE;
	}

	pNtHeader = (PIMAGE_NT_HEADERS)(fileBuff + pDosHeader->e_lfanew);
	if (pNtHeader->Signature != IMAGE_NT_SIGNATURE)
	{
		return FALSE;
	}

	pFileHeader = &pNtHeader->FileHeader;
	pOptionHeader = &pNtHeader->OptionalHeader;

	return TRUE;
}

void CPeUtil::printSectionHeaders()
{
	//PIMAGE_SECTION_HEADER pSectionHeaders = IMAGE_FIRST_SECTION(pNtHeader);

	/*for (int i = 0; i < pFileHeader->NumberOfSections; i++)
	{
		char name[9]{ 0 };
		memcpy_s(name, 9, pSectionHeaders->Name, 8);
		printf("区域名称为: %s\n", name);
		pSectionHeaders++;
	}*/

	WORD *SizeOfOptionHeader = (WORD*)((char*)pNtHeader + 20); //可选头大小
	WORD* numberOfSections = (WORD*)((char*)pNtHeader + 6); //区段数量
	char* pSectionHeaders1 = ((char*)pNtHeader + 24 + *SizeOfOptionHeader);//第一个区段地址
	
	for (int i = 0; i < *numberOfSections; i++) {
		char name1[9]{ 0 };
		memcpy_s(name1, 9, pSectionHeaders1, 8);
		printf("%s\n", name1);
		pSectionHeaders1 += 40; //每个区段头40个字节
	}

}

DWORD CPeUtil::RvaToFoa(DWORD rva)
{
	PIMAGE_SECTION_HEADER pSectionHeaders = IMAGE_FIRST_SECTION(pNtHeader);

	for (int i = 0; i < pFileHeader->NumberOfSections; i++)
	{
		if (rva >= pSectionHeaders->VirtualAddress && rva < pSectionHeaders->VirtualAddress + pSectionHeaders->Misc.VirtualSize)
		{
			return rva - pSectionHeaders->VirtualAddress + pSectionHeaders->PointerToRawData;
		}

		pSectionHeaders++;
	}
	return 0;
}

//导出表
void CPeUtil::GetExportTable()
{
	IMAGE_DATA_DIRECTORY directory = pOptionHeader->DataDirectory[0];
	PIMAGE_EXPORT_DIRECTORY exportTable = (PIMAGE_EXPORT_DIRECTORY)(RvaToFoa(directory.VirtualAddress) + fileBuff);

	DWORD *funcAddrs = (DWORD*)(RvaToFoa(exportTable->AddressOfFunctions) + fileBuff);
	WORD* pOrdinals = (WORD*)(RvaToFoa(exportTable->AddressOfNameOrdinals) + fileBuff);
	DWORD* names = (DWORD*)(RvaToFoa(exportTable->AddressOfNames) + fileBuff);

	char* dllName = RvaToFoa(exportTable->Name) + fileBuff;
	printf("DLL文件名称为:%s\n", dllName);

	for (int i = 0; i < exportTable->NumberOfFunctions; i++)
	{
		printf("函数地址为:%x\n", funcAddrs[i]);
		for (int j = 0; j < exportTable->NumberOfNames; j++)
		{
			if (pOrdinals[j] == i)
			{

				printf("函数名称为:%s\n", RvaToFoa(names[j]) + fileBuff);
				break;
			}
		}
	}
}

//导入表
void CPeUtil::GetImportTable()
{
	IMAGE_DATA_DIRECTORY directory = (IMAGE_DATA_DIRECTORY)pOptionHeader->DataDirectory[1];
	PIMAGE_IMPORT_DESCRIPTOR pImport = (PIMAGE_IMPORT_DESCRIPTOR)(RvaToFoa(directory.VirtualAddress) + fileBuff);

	while (pImport->OriginalFirstThunk)
	{
		char *dllName = (RvaToFoa(pImport->Name) + fileBuff);
		printf("dll文件名称为:%s\n", dllName);

		PIMAGE_THUNK_DATA pThunkData = (PIMAGE_THUNK_DATA)(RvaToFoa(pImport->OriginalFirstThunk) + fileBuff);
		while (pThunkData->u1.Function)
		{
			if (pThunkData->u1.Ordinal & 0x80000000)
			{
				printf("按序号导入:%d\n", pThunkData->u1.Ordinal & 0x7FFFFFFF);
			}
			else
			{
				PIMAGE_IMPORT_BY_NAME importName = (PIMAGE_IMPORT_BY_NAME)(RvaToFoa(pThunkData->u1.Ordinal) + fileBuff);

				printf("按名称导入:%s\n", importName->Name);
			}
			pThunkData++;
		}
		pImport++;
	}
}

//重定位表
void CPeUtil::GetRelocation()
{
	IMAGE_DATA_DIRECTORY directory = pOptionHeader->DataDirectory[5];
	PIMAGE_BASE_RELOCATION pRelocation =  (PIMAGE_BASE_RELOCATION)(RvaToFoa(directory.VirtualAddress) + fileBuff);

	while (pRelocation->VirtualAddress)
	{
		DWORD number = (pRelocation->SizeOfBlock - 8) / 2;
		WORD* offset = (WORD*)pRelocation + 4;

		for (int i = 0; i < number; i++)
		{
			if ((*offset & 0x3000) == 0x3000) //高四位为3需要修复
			{
				DWORD rva = (*offset & 0x0FFF) + pRelocation->VirtualAddress;
				printf("rva = %x\n", rva);
			}
			offset++;
		}
		pRelocation = (PIMAGE_BASE_RELOCATION)((DWORD)pRelocation + pRelocation->SizeOfBlock);
	}
	

}
