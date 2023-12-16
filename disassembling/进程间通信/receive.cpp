#include <Windows.h>
#include "resource.h"

INT_PTR CALLBACK WinProc(
	HWND hwnd,
	UINT msg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (msg)
	{
		case WM_COPYDATA:
		{
			PCOPYDATASTRUCT copyData = (PCOPYDATASTRUCT)lParam;
			MessageBox(hwnd, (LPCWSTR)copyData->lpData, L"ÌבÊ¾", MB_OK);
			break;
		}
		case WM_CLOSE:
		{
			EndDialog(hwnd, 0);
			break;
		}
		default:
			return FALSE;

	}

	return TRUE;
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPreInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{

	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, WinProc);
	return 0;
}