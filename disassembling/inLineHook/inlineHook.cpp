#include <Windows.h>
#include "inlineHook.h"

int WINAPI MyMessageBoxW(
	HWND    hWnd,
	LPCWSTR lpText,
	LPCWSTR lpCaption,
	UINT    uType
)
{
	UnInstallHook();
	int result = MessageBoxW(hWnd, L"666", lpCaption, uType);
	InstallHook();
	return result;
}

BOOL InstallHook()
{
	DWORD oldProtect = 0;
	VirtualProtect((DWORD*)oldFuncAddr, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((DWORD*)oldFuncAddr, newCode, 5);
	VirtualProtect((DWORD*)oldFuncAddr, 5, oldProtect, &oldProtect);
	return TRUE;
}

BOOL UnInstallHook()
{
	DWORD oldProtect = 0;
	VirtualProtect((DWORD*)oldFuncAddr, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy((DWORD*)oldFuncAddr, oldCode, 5);
	VirtualProtect((DWORD*)oldFuncAddr, 5, oldProtect, &oldProtect);
	return TRUE;
}
BOOL InitHook()
{
	//找到要HOOK的函数地址
	HMODULE hModule = LoadLibraryA("user32.dll");
	if (hModule == 0)
	{
		return FALSE;
	}
	oldFuncAddr = (DWORD)GetProcAddress(hModule, "MessageBoxW"); //32位 64位转换为8字节

	//保留函数前5个字节 32位地址4字节,jmp(E9)一个字节
	memcpy(oldCode, (char*)oldFuncAddr, 5);

	//计算偏移
	offset = (DWORD)MyMessageBoxW - (oldFuncAddr + 5);

	//保存HOOK后的5个字节
	memcpy(&newCode[1], &offset, 4);
	return TRUE;
	
}
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		InitHook();
		InstallHook();
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		UnInstallHook();
	}
	return TRUE;
}