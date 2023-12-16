#include <Windows.h>
#include <iostream>

void _declspec(naked) asmHashCode1()
{
	_asm
	{
		push ebp
		mov ebp, esp
		sub esp, 0x10
		push ebx
		push edx
		push esi
		mov dword ptr[ebp - 0x4], 0x0 //局部变量1
		mov esi, [ebp + 0x8] //参数1
		xor eax,eax
	flag_while:
		mov al, [esi]
		test al,al
		je flag_end
		mov ebx, [ebp - 0x4]
		shl ebx, 0x19
		mov edx, [ebp - 0x4]
		shr edx, 0x7
		or ebx, edx
		add ebx,eax
		mov[ebp - 0x4], ebx
		inc esi
		jmp flag_while
	flag_end:
		mov eax,ebx
		pop esi
		pop edx
		pop ebx
		mov esp,ebp
		pop ebp
		ret 0x4
	}
}

DWORD getHashCode(char* str)
{
	DWORD target = 0;
	while (*str)
	{
		target = (target << 25 | target >> 7);
		target = target + *str;
		str++;
	}
	return target;
}
char str[] = "LoadLibraryExA";
int main5(void)
{
	_asm
	{
		lea ebx,str
		push ebx
		call asmHashCode1

	}
	//printf("%x\n", getHashCode((char*)"LoadLibraryExA"));//c0d83287
	//printf("%x\n", getHashCode((char*)"GetProcAddress"));//bbafdf85
	//printf("%x\n", getHashCode((char*)"MessageBoxA"));//1e380a6a
	printf("%x\n", getHashCode((char*)"WSAStartup")); //80b46a3d
	printf("%x\n", getHashCode((char*)"WSASocketA")); //de78322d
	printf("%x\n", getHashCode((char*)"bind")); //dda71064
	printf("%x\n", getHashCode((char*)"listen"));//4bd39f0c
	printf("%x\n", getHashCode((char*)"accept"));//1971eb1
	printf("%x\n", getHashCode((char*)"CreateProcessA"));//6ba6bcc9
	printf("%x\n", getHashCode((char*)"ExitProcess"));//4fd18963
	
	
	return 0;
}