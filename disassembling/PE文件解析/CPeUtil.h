#pragma once
#include <Windows.h>

class CPeUtil
{
public:
	CPeUtil();
	~CPeUtil();
	BOOL loadFile(const char* );
	BOOL initPeInfo();
	void printSectionHeaders();
	DWORD RvaToFoa(DWORD rva);
	void GetExportTable();
	void GetImportTable();
	void GetRelocation();
private:
	char* fileBuff;
	DWORD fileSize;
	PIMAGE_DOS_HEADER pDosHeader;
	PIMAGE_NT_HEADERS pNtHeader;
	PIMAGE_FILE_HEADER pFileHeader;
	PIMAGE_OPTIONAL_HEADER pOptionHeader;
};