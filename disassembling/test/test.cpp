#include <Windows.h>

BOOL DllMain(HINSTANCE hInstance, DWORD reason, LPVOID lp)
{
	if (reason == DLL_THREAD_ATTACH)
	{
		MessageBoxA(0, "dll注入成功", "提示", MB_OK);
	}
	return TRUE;
}