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
	//�ҵ�ҪHOOK�ĺ�����ַ
	HMODULE hModule = LoadLibraryA("user32.dll");
	if (hModule == 0)
	{
		return FALSE;
	}
	oldFuncAddr = (DWORD)GetProcAddress(hModule, "MessageBoxW"); //32λ 64λת��Ϊ8�ֽ�

	//��������ǰ5���ֽ� 32λ��ַ4�ֽ�,jmp(E9)һ���ֽ�
	memcpy(oldCode, (char*)oldFuncAddr, 5);

	//����ƫ��
	offset = (DWORD)MyMessageBoxW - (oldFuncAddr + 5);

	//����HOOK���5���ֽ�
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