#include <Windows.h>
#include <stdio.h>
//jmp esp  0x75A2C823
void _declspec(naked)shellCode()
{
	_asm
	{	//H  e  l  l  o     W  o  r  l  d
		//48 65 6C 6C 6F 20 57 6F 72 6C 64
		push 0x646C72
		push 0x6F57206F
		push 0x6C6C6548
		mov eax,esp
		push 0;
		push 0;
		push eax;
		push 0;
		//76BE10D0
		mov eax, 0x76BE10D0;
		call eax;
	}
}
int main1(void)
{
	printf("hello\n");
	shellCode();

	return 0;
}