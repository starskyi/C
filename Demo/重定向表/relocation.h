#pragma once
#include <Windows.h>
typedef struct _PACKINFO
{
	DWORD oldOEP;
	DWORD newOEP;
}PACKINFO, * PPACKINFO;

extern "C" _declspec(dllexport) PACKINFO g_PackInfo;
