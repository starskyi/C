#pragma once
#include <Windows.h>

int WINAPI MyMessageBoxW(
	HWND   hWnd,
	LPCSTR lpText,
	LPCSTR lpCaption,
	UINT   uType
);
BOOL InstallHook();
BOOL UnInstallHook();
DWORD* GetIatAddr(const char* dllName, const char* dllFunName);