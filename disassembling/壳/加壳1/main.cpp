#include <Windows.h>
#include "CPeUtil.h"
typedef struct _PACKINFO
{
	DWORD oldOEP;
	DWORD newOEP;
}PACKINFO, * PPACKINFO;
int main(void)
{
	CPeUtil peUtil;
	peUtil.loadFile("MFC1.exe");
	peUtil.EncodeSections();
	HMODULE dllBase = LoadLibraryA("pack.dll");
	PPACKINFO pPackInfo = (PPACKINFO)GetProcAddress(dllBase, "g_PackInfo");
	pPackInfo->oldOEP = peUtil.GetOldOEPva();
	PIMAGE_DOS_HEADER dllDosHeader = (PIMAGE_DOS_HEADER)(dllBase);
	PIMAGE_NT_HEADERS dllNtHeader = (PIMAGE_NT_HEADERS)(dllDosHeader->e_lfanew + (DWORD)dllBase);
	PIMAGE_SECTION_HEADER pSectionHeader = IMAGE_FIRST_SECTION(dllNtHeader);
	PIMAGE_SECTION_HEADER pLSectionHeader = pSectionHeader + dllNtHeader->FileHeader.NumberOfSections - 1;
	DWORD size = pLSectionHeader->VirtualAddress - pSectionHeader->VirtualAddress + pLSectionHeader->Misc.VirtualSize;

	char* codeBuff = (char*)(pSectionHeader->VirtualAddress + (DWORD)dllBase);
	peUtil.InsertSection("star",size, codeBuff, 0XE00000E0);
	peUtil.RepairRelocation((DWORD)dllBase);
	peUtil.RepairRelocation2((DWORD)dllBase);
	DWORD offsetOEP = pPackInfo->newOEP - (DWORD)dllBase - pSectionHeader->VirtualAddress;
	peUtil.SetNewOEP(offsetOEP);
	peUtil.SavaFile("newMFC2.exe");
	
	return 0;
}