#include <Windows.h>

BOOL DllMain(HINSTANCE hInstance, DWORD reason, LPVOID lp)
{
	if (reason == DLL_THREAD_ATTACH)
	{
		MessageBoxA(0, "dllע��ɹ�", "��ʾ", MB_OK);
	}
	return TRUE;
}