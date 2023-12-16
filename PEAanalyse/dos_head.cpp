#include <Windows.h>
#include <iostream>

int main(void)
{
	HANDLE hFile = CreateFileA("D:\\code\\C\\working\\Debug\\working.exe", 
		GENERIC_READ, 
		FILE_SHARE_READ, 
		NULL, 
		OPEN_EXISTING, 
		FILE_ATTRIBUTE_NORMAL, 
		0);

	DWORD fileSize = GetFileSize(hFile, NULL);
	char* peFile = new char[fileSize]; //读取的PE文件
	DWORD realRead;
	BOOL flag = ReadFile(hFile, peFile, fileSize, &realRead, NULL);

	if (flag)
	{
		PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)peFile; 
		PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((DWORD)peFile + pDosHeader->e_lfanew);

		DWORD pe = pNtHeader->Signature;
		DWORD* pe2 = (DWORD*)((DWORD)peFile + pDosHeader->e_lfanew);
		printf("signature1 = %d, signature2 =  %d\n", pe, *pe2);

		if (pDosHeader->e_magic != 0X5A4D || pe != 0x4550)
		{
			printf("不是有效的PE文件\n");
		}
		else {
			
			PIMAGE_FILE_HEADER pFileHeader = &pNtHeader->FileHeader;
			PIMAGE_FILE_HEADER pFileHeader2 = (PIMAGE_FILE_HEADER)((DWORD*)((DWORD)peFile + pDosHeader->e_lfanew) + 1);
			WORD* machine = (WORD*)((DWORD*)((DWORD)peFile + pDosHeader->e_lfanew) + 1);


			printf("e_lfanew=%x\n", pDosHeader->e_lfanew);
			printf("pFileHeader->Machine:%x, pFileHeader2->Machine:%x %x\n", pFileHeader->Machine, pFileHeader2->Machine, *machine);
			printf("pFileHeader->Characteristics:%x\n", pFileHeader->Characteristics);
			printf("pFileHeader->NumberOfSections:%d\n", pFileHeader->NumberOfSections);
			printf("pFileHeader->SizeOfOptionalHeader:%d, pFileHeader2->....:%d\n", pFileHeader->SizeOfOptionalHeader, pFileHeader2->SizeOfOptionalHeader);
		}
		
	}
	if (hFile)
	{
		CloseHandle(hFile);
	}
	delete[] peFile;

}
