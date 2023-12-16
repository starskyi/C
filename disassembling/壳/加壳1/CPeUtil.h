#pragma once
#include <Windows.h>

class CPeUtil
{
private:
	char *fileBuff;
	DWORD fileSize;
	DWORD importsSize;
	PIMAGE_DOS_HEADER pDosHeader;
	PIMAGE_NT_HEADERS pNtHeader;
	PIMAGE_FILE_HEADER pFileHeader;
	PIMAGE_OPTIONAL_HEADER pOptionHeader;
	

public:
	CPeUtil();
	~CPeUtil();
	BOOL loadFile(const char* path);
	BOOL InitFileInfo();
	BOOL InsertSection(const char* sectionName, DWORD codeSize, char* codeBuff, DWORD dwCharacteristics);
	DWORD GetAlignSize(DWORD realSize, DWORD alignSize);
	PIMAGE_SECTION_HEADER GetLastSectionHeader();
	BOOL EncodeSections();
	DWORD GetOldOEPva();
	BOOL SavaFile(const char* path);
	BOOL SetNewOEP(DWORD opeRva);
	BOOL RepairRelocation(DWORD imageBase);
	BOOL RepairRelocation2(DWORD imageBase);
	DWORD GetImportTable();
	DWORD RvaToFoa(DWORD rva);
	DWORD FoaToRva(DWORD foa);
	DWORD GetImportsTableSize();
};
