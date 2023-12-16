#include <Windows.h>
#include "pack.h"
//将代码段和数据段合并到一起
#pragma comment(linker, "/merge:.data=.text")
#pragma comment(linker, "/merge:.rdata=.text")
#pragma comment(linker, "/section:.text,RWE")

void packStart();
PACKINFO g_PackInfo = { 0, (DWORD)packStart};
typedef HMODULE (WINAPI* MyLoadLibraryExA)(LPCSTR lpLibFileName, HANDLE hFile, DWORD dwFlags);
typedef FARPROC (WINAPI* MYGetProcAddress)(
	HMODULE hModule,
	LPCSTR  lpProcName
);
typedef HMODULE (WINAPI* MyGetModuleHandleA)(
	LPCSTR lpModuleName
);
typedef BOOL (WINAPI *MyVirtualProtect)(
	LPVOID lpAddress,
	SIZE_T dwSize,
	DWORD  flNewProtect,
	PDWORD lpflOldProtect
);
typedef int (WINAPI *MyMessageBoxA)(
	HWND   hWnd,
	LPCSTR lpText,
	LPCSTR lpCaption,
	UINT   uType
);

MyLoadLibraryExA g_MyLoadLibraryExA = NULL;
MYGetProcAddress g_MyGetProcAddress = NULL;
MyGetModuleHandleA g_MyGetModuleHandleA = NULL;
MyVirtualProtect g_MyVirtualProtect = NULL;
MyMessageBoxA g_MyMessageBoxA = NULL;



DWORD GetImportantModule()
{
	DWORD dwBase = 0;
	__asm {
		mov eax,dword ptr fs:[0x30]
		mov eax,dword ptr [eax+0xc]
		mov eax,dword ptr [eax+0x1c]
		mov eax,[eax]
		mov eax,dword ptr[eax+0x8]
		mov dwBase,eax
	}
	return dwBase;
}

DWORD MyGetProcAddress(DWORD hModule, LPCSTR funName)
{
	
	
	//获取Dos头和NT头
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(hModule + pDosHeader->e_lfanew);
	//获取导出表
	PIMAGE_EXPORT_DIRECTORY exportTable = (PIMAGE_EXPORT_DIRECTORY)(
		pNtHeader->OptionalHeader.DataDirectory[0].VirtualAddress + hModule);
	//获取导出地址表，导出名称表，导出序号表
	DWORD* eat = (DWORD*)(hModule + exportTable->AddressOfFunctions);
	DWORD* ent = (DWORD*)(hModule + exportTable->AddressOfNames);
	WORD* eot = (WORD*)(hModule + exportTable->AddressOfNameOrdinals);
	for (int i = 0; i < exportTable->NumberOfNames; i++)
	{
		char* name = (char*)(hModule + ent[i]);
		if (!strcmp(name, funName)) //两个字符串相等返回0
		{
			return eat[eot[i]] + hModule;
		}
	}
	return 0;
}

void GetFunctions()
{

	//获取 kernel32 或 kernelBase模块基址
	DWORD pKernelBase = GetImportantModule();
	//获取LoadLibraryEx地址
	g_MyLoadLibraryExA = (MyLoadLibraryExA)MyGetProcAddress(pKernelBase, "LoadLibraryExA");
	//获取 kernel32基址
	HMODULE kernelBase = g_MyLoadLibraryExA("kernel32.dll", 0, 0);
	HMODULE user32 = g_MyLoadLibraryExA("user32.dll", 0, 0);
	g_MyGetProcAddress = (MYGetProcAddress)(MyGetProcAddress((DWORD)kernelBase, "GetProcAddress"));
	g_MyGetModuleHandleA = (MyGetModuleHandleA)(g_MyGetProcAddress(kernelBase, "GetModuleHandleA"));
	g_MyVirtualProtect = (MyVirtualProtect)(g_MyGetProcAddress(kernelBase, "VirtualProtect"));
	g_MyMessageBoxA = (MyMessageBoxA)(g_MyGetProcAddress(user32, "MessageBoxA"));
	
}

BOOL DecodeSection()
{
	int key = 0x51;
	HMODULE hModule = g_MyGetModuleHandleA(0);
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)hModule;
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)((DWORD)hModule + pDosHeader->e_lfanew);
	PIMAGE_SECTION_HEADER pFirstSection = IMAGE_FIRST_SECTION(pNtHeader);
	char* sectionData = (char*)(pFirstSection->VirtualAddress + (DWORD)hModule);
	DWORD oldProtect = 0;
	g_MyVirtualProtect(sectionData, pFirstSection->SizeOfRawData, PAGE_EXECUTE_READWRITE, &oldProtect);
	for (int i = 0; i < pFirstSection->SizeOfRawData; i++)
	{
		sectionData[i] = sectionData[i] ^ key;
	}
	g_MyVirtualProtect(sectionData, pFirstSection->SizeOfRawData, oldProtect, &oldProtect);
	return TRUE;
	
}
_declspec(naked) void packStart()
{
	_asm pushad
	GetFunctions();
	DecodeSection();
	g_MyMessageBoxA(0, "壳代码执行了", 0, 0);
	_asm popad
	_asm jmp g_PackInfo.oldOEP
	
}


