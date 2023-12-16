#include <Windows.h>
#include <iostream>
#include "relocation.h"
#pragma comment(linker, "/merge:.data=.text")
#pragma comment(linker, "/merge:.rdata=.text")
#pragma comment(linker, "/section:.text,RWE")
void packStart();
PACKINFO g_PackInfo = { 0, (DWORD)packStart };
char name[] = "hello world";
_declspec(naked) void packStart()
{
	_asm pushad
	_asm push name
	_asm popad
	_asm jmp g_PackInfo.oldOEP

}