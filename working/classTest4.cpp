#include <iostream>
#include <Windows.h>


class Student
{
public:
	int age = 18;
	char name[32] = "zhangsan";
	virtual void showName()
	{
		printf("%s\n", name);
	}

	void showAge()
	{
		printf("%d\n", age);
	}
};

void run()
{
	printf("run.....\n");
}

int main(void)
{
	Student student;
	
	Student* pst = &student;
	LPVOID funcAddr;
	DWORD flOldProtect;
	_asm
	{
		mov eax, [pst];
		mov eax, [eax];
		mov funcAddr, eax;
		push eax;
	}
	
	VirtualProtect(funcAddr, 0x4, PAGE_EXECUTE_READWRITE, &flOldProtect);

	_asm
	{
		pop eax;
		mov ebx, run;
		mov[eax], ebx;
	}
	VirtualProtect(funcAddr, 0x4, flOldProtect, &flOldProtect);

	pst->showName();
	pst->showAge();
	run();
	return 0;
}