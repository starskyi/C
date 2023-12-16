#include "iatHook.h"

DWORD* g_iatAddr = NULL;
DWORD* g_oldFunAddr = NULL;
int WINAPI MyMessageBoxW(
	HWND   hWnd,
	LPCSTR lpText,
	LPCSTR lpCaption,
	UINT   uType
)
{
	
	return MessageBoxA(NULL, "IAT注入成功", "提示", MB_OK);
}

BOOL InstallHook()
{
	DWORD oldProtect = 0;
	VirtualProtect(g_iatAddr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
	*g_iatAddr = (DWORD)MyMessageBoxW;
	VirtualProtect(g_iatAddr, 4, oldProtect, &oldProtect);
	return TRUE;
}

BOOL UnInstallHook()
{
	DWORD oldProtect = 0;
	VirtualProtect(g_iatAddr, 4, PAGE_EXECUTE_READWRITE, &oldProtect);
	*g_iatAddr = (DWORD)g_oldFunAddr;
	VirtualProtect(g_iatAddr, 4, oldProtect, &oldProtect);
	return TRUE;
}

DWORD* GetIatAddr(const char* dllName, const char* dllFunName)
{
	//获取当前进程句柄
	HMODULE hModule = GetModuleHandle(0);
	unsigned long long dwModule = (unsigned long long)hModule;

	//获取Dos头
	PIMAGE_DOS_HEADER pDosHeader = (PIMAGE_DOS_HEADER)dwModule;
	//获取NT头
	PIMAGE_NT_HEADERS pNtHeader = (PIMAGE_NT_HEADERS)(pDosHeader->e_lfanew + dwModule);
	//获取可选头
	PIMAGE_OPTIONAL_HEADER pOptionalHeader = &pNtHeader->OptionalHeader;

	//获取导入表
	IMAGE_DATA_DIRECTORY  directory = pOptionalHeader->DataDirectory[1];
	PIMAGE_IMPORT_DESCRIPTOR pImportTable = (PIMAGE_IMPORT_DESCRIPTOR)(directory.VirtualAddress + dwModule);

	while (pImportTable->Name)
	{
		char* iatDllName = (char*)(pImportTable->Name + dwModule);
		if (_stricmp(dllName, iatDllName) == 0)
		{
			PIMAGE_THUNK_DATA thunkData = (PIMAGE_THUNK_DATA)(pImportTable->OriginalFirstThunk + dwModule);
			PIMAGE_THUNK_DATA pIAT = (PIMAGE_THUNK_DATA)(pImportTable->FirstThunk + dwModule);
			while (thunkData->u1.Function)
			{
				if ((thunkData->u1.Ordinal & 0x80000000) == 0)
				{

					PIMAGE_IMPORT_BY_NAME pImportName = PIMAGE_IMPORT_BY_NAME(thunkData->u1.Ordinal + dwModule);
					if (strcmp(dllFunName, pImportName->Name) == 0)
					{
						return (DWORD*)pIAT;
					}
				}
				thunkData++;
				pIAT++;
			}
			
		}
		pImportTable++;
	}
}

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		g_iatAddr = GetIatAddr("user32.dll", "MessageBoxW");
		g_oldFunAddr = (DWORD*)*g_iatAddr;
		InstallHook();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		UnInstallHook();
	}
	return TRUE;
}