#include <Windows.h>

int main(void)
{
	LoadLibraryA("inLineHook.dll");
	MessageBoxW(0, L"hello world", L"��ʾ", MB_OK);
	return 0;
}