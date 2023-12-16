#include <Windows.h>
#include <iostream>

typedef BOOL(*InstallHook)();
typedef BOOL(*UnInstallHook)();

int main(void)
{
	HMODULE hModule = LoadLibraryA("HOOK.dll");

	InstallHook myInstallHook = (InstallHook)GetProcAddress(hModule, "InstallHook");
	UnInstallHook myUnInstallHook = (UnInstallHook)GetProcAddress(hModule, "UnInstallHook");

	if (myInstallHook())
	{
		printf("HOOK³É¹¦\n");
		
	}
	system("pause");
	myUnInstallHook();
	return 0;
}