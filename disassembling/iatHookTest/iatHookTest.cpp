#include <Windows.h>

int main(void)
{
	MessageBoxW(0, L"hello world", L"��ʾ", 0);
	HMODULE hModule = LoadLibraryA("IAThook.dll");
	if (hModule)
	{
		MessageBoxW(0, L"hello world", L"��ʾ", 0);
	}
	
	return 0;
}