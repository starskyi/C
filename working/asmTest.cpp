#include <stdio.h>
#include <Windows.h>
void _declspec(naked) fun1(char *str)
{
	_asm 
	{
		push ebp;
		mov ebp, esp;
		sub esp, 0x20;
		push 0;
		push 0;
		mov eax, [ebp + 0x8]
		push eax;
		push 0;
		call MessageBoxA;
		add esp, 0x20;
		pop ebp;
		ret 0x4;
	}
}

void fun2(char* str)
{
	MessageBoxA(0, str, 0, 0);
}

int main()
{
	char str[] = "hello world";
	//fun2(str);
	_asm 
	{
		lea eax, [str];
		push eax;
		call fun1;
	}
}