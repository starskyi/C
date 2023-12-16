#include <Windows.h>

int main(void)
{
	MessageBoxW(0, L"hello world", L"提示", 0);
	HMODULE hModule = LoadLibraryA("IAThook.dll");
	if (hModule)
	{
		MessageBoxW(0, L"hello world", L"提示", 0);
	}
	
	return 0;
}