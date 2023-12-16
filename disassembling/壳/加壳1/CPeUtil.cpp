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
	delete[] fileBuff;
}

BOOL CPeUtil::loadFile(const char* path)
{
	//���ļ�
	HANDLE hFile = CreateFileA(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	//��ȡ�ļ���С
	fileSize = GetFileSize(hFile, 0);
	fileBuff = new char[fileSize];
	//��ȡ�ļ�
	DWORD realRead = 0;
	BOOL success = ReadFile(hFile, fileBuff, fileSize, &realRead, NULL);
	if (!success)
	{
		MessageBoxA(0, "�ļ���ʧ��", "����", MB_OK);
		return FALSE;
	}
	InitFileInfo();
	return TRUE;
}

BOOL CPeUtil::InitFileInfo()
{
	pDosHeader = (PIMAGE_DOS_HEADER)fileBuff;
	pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + fileBuff);
	pFileHeader = &pNtHeader->FileHeader;
	pOptionHeader = &pNtHeader->OptionalHeader;

	return 0;
}

BOOL CPeUtil::InsertSection(const char* sectionName, DWORD codeSize, char* codeBuff, DWORD dwCharacteristics)
{
	importsSize = GetImportsTableSize();
	codeSize += importsSize;
	//��ȡ�����PE�ļ���С
	DWORD newFileSize = GetAlignSize(fileSize + codeSize, pOptionHeader->FileAlignment);
	//�����µĻ��������PE�ļ�
	char* newFileBuff = new char[newFileSize] {0};
	memcpy_s(newFileBuff, newFileSize, fileBuff, fileSize);
	delete[] fileBuff;
	fileBuff = newFileBuff;
	fileSize = newFileSize;
	InitFileInfo();

	//������������κ��NumberOfSection��SizeOfImage
	pFileHeader->NumberOfSections++;
	pOptionHeader->SizeOfImage += GetAlignSize(codeSize, pOptionHeader->SectionAlignment);
	//�������������������ͷ
	PIMAGE_SECTION_HEADER pNewSectionHeader = GetLastSectionHeader();
	PIMAGE_SECTION_HEADER pLastSectionHeader = GetLastSectionHeader()-1;
	
	//��������ͷ��������
	// ������������
	strcpy_s((char*)pNewSectionHeader->Name, 8, sectionName);
	//�����ڴ��С
	pNewSectionHeader->Misc.VirtualSize = GetAlignSize(codeSize, pOptionHeader->SectionAlignment);
	//�������ڴ��е�ƫ��
	pNewSectionHeader->VirtualAddress = pLastSectionHeader->VirtualAddress +
		GetAlignSize(pLastSectionHeader->Misc.VirtualSize, pOptionHeader->SectionAlignment);
	//�����������ļ��ж����Ĵ�С
	pNewSectionHeader->SizeOfRawData = GetAlignSize(codeSize, pOptionHeader->FileAlignment);
	//�����������ļ��е�ƫ��λ��
	pNewSectionHeader->PointerToRawData = pLastSectionHeader->PointerToRawData + pLastSectionHeader->SizeOfRawData;
	//������������
	pNewSectionHeader->Characteristics = dwCharacteristics;
	//���Ǵ���ŵ�������
	char* sectionAddr = GetLastSectionHeader()->PointerToRawData + fileBuff;
	memcpy(sectionAddr, codeBuff, codeSize - importsSize);

	//�������ŵ�������
	char* pImports = (char*)GetImportTable();
	sectionAddr += (codeSize - importsSize);
	memcpy(sectionAddr, pImports, importsSize);
	pOptionHeader->DataDirectory[1].VirtualAddress =  FoaToRva((DWORD)sectionAddr - (DWORD)fileBuff);
	return 0;
}

DWORD CPeUtil::GetAlignSize(DWORD realSize, DWORD alignSize)
{
	if (realSize % alignSize == 0)
	{
		return realSize;
	}
	else
	{
		return (realSize / alignSize + 1) * alignSize;
	}
}

PIMAGE_SECTION_HEADER CPeUtil::GetLastSectionHeader()
{
	PIMAGE_SECTION_HEADER firstSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);
	return firstSectionHeader + (pFileHeader->NumberOfSections - 1);
}

BOOL CPeUtil::EncodeSections()
{
	PIMAGE_SECTION_HEADER pSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);
	int key = 0x51;
	char* pData = pSectionHeader->PointerToRawData + fileBuff;
	for (int i = 0; i < pSectionHeader->SizeOfRawData; i++)
	{
		pData[i] = pData[i] ^ key;
	}
	
	return TRUE;
}

DWORD CPeUtil::GetOldOEPva()
{
	return pOptionHeader->AddressOfEntryPoint + pOptionHeader->ImageBase;
}

BOOL CPeUtil::SavaFile(const char *path)
{
	HANDLE hFile = CreateFileA(path, GENERIC_WRITE, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	if (hFile == 0)
	{
		return FALSE;
	}
	DWORD realWrite = 0;
	BOOL result = WriteFile(hFile, fileBuff, fileSize, &realWrite, 0);
	CloseHandle(hFile);
	return result;
}

BOOL CPeUtil::SetNewOEP(DWORD opeRva)
{
	pOptionHeader->AddressOfEntryPoint = GetLastSectionHeader()->VirtualAddress + opeRva;
	return TRUE;
}

BOOL CPeUtil::RepairRelocation(DWORD imageBase)
{

	PIMAGE_DOS_HEADER dllDosHeader = (PIMAGE_DOS_HEADER)(imageBase);
	PIMAGE_NT_HEADERS dllNtHeader = (PIMAGE_NT_HEADERS)(dllDosHeader->e_lfanew + imageBase);
	PIMAGE_OPTIONAL_HEADER dllOptionHeader = &dllNtHeader->OptionalHeader;
	IMAGE_DATA_DIRECTORY directory = (IMAGE_DATA_DIRECTORY)dllOptionHeader->DataDirectory[5];
	PIMAGE_SECTION_HEADER sectionHeader = IMAGE_FIRST_SECTION(dllNtHeader);
	PIMAGE_BASE_RELOCATION relocation = (PIMAGE_BASE_RELOCATION)(directory.VirtualAddress + imageBase);
	
	//��ȡ�����������ʼ��ַ
	DWORD newFileAddr = (DWORD)(GetLastSectionHeader()->PointerToRawData + fileBuff);
	DWORD newSectionAddr = (DWORD)(GetLastSectionHeader()->VirtualAddress + pOptionHeader->ImageBase);
	int count = 1;
	while (relocation->SizeOfBlock != 0)
	{
		DWORD repairNumber = (relocation->SizeOfBlock - 8) / 2;
		WORD* starRepair = (WORD*)relocation + 8/2;
		
		for (int i = 0; i < repairNumber; i++)
		{
			WORD currRepair = starRepair[i];
			

			if ((currRepair & 0x3000) == 0x3000)//����λΪ3��Ҫ�޸�
			{
				//��ȡ��Ҫ�ض�λ������ַ
				DWORD repairRva = (DWORD)((currRepair & 0x0FFF) + relocation->VirtualAddress);
				DWORD relRepairAddr = (DWORD)(repairRva + imageBase);
				
				//��ȡ������ fileBuff�еĵ�ַ
				DWORD *destAddr = (DWORD*)(relRepairAddr - imageBase - sectionHeader->VirtualAddress + newFileAddr);
				
				*destAddr = (DWORD)(*destAddr - imageBase - sectionHeader->VirtualAddress + newSectionAddr);
			}
		}
		count++;
		relocation = (PIMAGE_BASE_RELOCATION)((DWORD)relocation + relocation->SizeOfBlock);
	}
	return 0;
}

BOOL CPeUtil::RepairRelocation2(DWORD imageBase)
{
	PIMAGE_DOS_HEADER dllDosHeader = (PIMAGE_DOS_HEADER)(imageBase);
	PIMAGE_NT_HEADERS dllNtHeader = (PIMAGE_NT_HEADERS)(dllDosHeader->e_lfanew + imageBase);
	PIMAGE_OPTIONAL_HEADER dllOptionHeader = &dllNtHeader->OptionalHeader;
	PIMAGE_SECTION_HEADER dllFirstSection = IMAGE_FIRST_SECTION(dllNtHeader);
	DWORD relocRva = dllOptionHeader->DataDirectory[5].VirtualAddress - dllFirstSection->VirtualAddress;
	PIMAGE_SECTION_HEADER pLastSectionHeader = GetLastSectionHeader();
	pOptionHeader->DataDirectory[5].VirtualAddress = relocRva + pLastSectionHeader->VirtualAddress;
	//pOptionHeader->DataDirectory[5].Size = dllOptionHeader->DataDirectory[5].Size;
	DWORD pLastSection = (DWORD)(RvaToFoa(pLastSectionHeader->VirtualAddress) + fileBuff);
	PIMAGE_BASE_RELOCATION pReloc = (PIMAGE_BASE_RELOCATION)((DWORD)pLastSection + relocRva);
	
	while (pReloc->SizeOfBlock) {
		pReloc->VirtualAddress = pLastSectionHeader->VirtualAddress + pReloc->VirtualAddress;
		pReloc = (PIMAGE_BASE_RELOCATION)((DWORD)pReloc + pReloc->SizeOfBlock);
	}

	return 0;
}

DWORD CPeUtil::GetImportTable()
{
	PIMAGE_IMPORT_DESCRIPTOR pImports = (PIMAGE_IMPORT_DESCRIPTOR)
		(RvaToFoa(pOptionHeader->DataDirectory[1].VirtualAddress) + fileBuff);
	return (DWORD)pImports;
}

DWORD CPeUtil::RvaToFoa(DWORD rva)
{
	PIMAGE_SECTION_HEADER nowSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);
	
	for (int i = 0; i < pFileHeader->NumberOfSections; i++)
	{
		if (rva >= nowSectionHeader->VirtualAddress &&
			rva < (nowSectionHeader->VirtualAddress + nowSectionHeader->Misc.VirtualSize))
		{
			return rva - nowSectionHeader->VirtualAddress + nowSectionHeader->PointerToRawData;
		}
		nowSectionHeader++;
	}
	return 0;
}

DWORD CPeUtil::FoaToRva(DWORD foa)
{
	PIMAGE_SECTION_HEADER nowSectionHeader = IMAGE_FIRST_SECTION(pNtHeader);

	for (int i = 0; i < pFileHeader->NumberOfSections; i++)
	{
		if (foa >= nowSectionHeader->PointerToRawData &&
			foa < (nowSectionHeader->PointerToRawData + nowSectionHeader->SizeOfRawData))
		{
			return foa - nowSectionHeader->PointerToRawData + nowSectionHeader->VirtualAddress;
		}
		nowSectionHeader++;
	}
	return 0;
}

DWORD CPeUtil::GetImportsTableSize()
{
	PIMAGE_IMPORT_DESCRIPTOR nowImport = (PIMAGE_IMPORT_DESCRIPTOR)
		(RvaToFoa(pOptionHeader->DataDirectory[1].VirtualAddress - pOptionHeader->ImageBase) + fileBuff);
	int len = 0;
	while (nowImport->Name)
	{
		len++;
		nowImport++;
	}
	return sizeof(PIMAGE_IMPORT_DESCRIPTOR) * len;
}


