#include "hook.h"

HINSTANCE g_hInstance = NULL;
HHOOK g_hHook = NULL;

LRESULT CALLBACK KeyboardProc(
	_In_ int    code,
	_In_ WPARAM wParam,
	_In_ LPARAM lParam
)
{
	if (code == HC_ACTION && (lParam & 0x80000000) == 0)
	{
		BYTE KeyState[256]{ 0 };
		if (GetKeyboardState(KeyState))
		{
			LONG keyInfo = lParam;
			UINT keyCode = (keyInfo >> 16) & 0x00ff;
			WCHAR wKeyCode = 0;
			ToAscii((UINT)wParam, keyCode, KeyState, (LPWORD)&wKeyCode, 0);
			CHAR strInfo[12] = { 0 };
			sprintf_s(strInfo, _countof(strInfo), "ƒ„µ„¡À:%c", wKeyCode);
			OutputDebugStringA(strInfo);
			return 0;
		}
	}
	return CallNextHookEx(g_hHook, code, wParam, lParam);
}

BOOL InstallHook()
{
	g_hHook = SetWindowsHookExA(WH_KEYBOARD, KeyboardProc, g_hInstance, 0);
	if (g_hHook)
	{
		return TRUE;
	}
	return FALSE;
}

BOOL UnInstallHook()
{
	return UnhookWindowsHookEx(g_hHook);
}

BOOL DllMain(HINSTANCE hInstance, DWORD dwCallReason, LPVOID lpReserved)
{
	if (dwCallReason == DLL_PROCESS_ATTACH) {
		g_hInstance = hInstance;
	}
	
	return TRUE;
}