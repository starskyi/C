#pragma once
#include <Windows.h>

DWORD oldFuncAddr = 0;
DWORD newFuncAddr = 0;
DWORD offset = 0;
char oldCode[5]{ 0 };
char newCode[5] = { 0xE9 };

int WINAPI MyMessageBoxW(
	HWND    hWnd,
	LPCWSTR lpText,
	LPCWSTR lpCaption,
	UINT    uType
);
BOOL InstallHook();
BOOL UnInstallHook();