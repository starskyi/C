#include <Windows.h>
#include <iostream>

int main(void)
{
	char *str = (char*)VirtualAlloc(0, 1, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	strcpy_s(str, 12, "hello world");
	printf("%s\n", str);
	VirtualFree(str, 0, MEM_RELEASE);


	char name[] = "51HOOK";
	char* cname = (char*)"51HOOK";
	DWORD oldProtect = 0;
	VirtualProtect(cname, 7, PAGE_READWRITE, &oldProtect);
	name[1] = '2';
	cname[1] = '2';
	printf("%s %s\n", name, cname);
	return 0;
}
