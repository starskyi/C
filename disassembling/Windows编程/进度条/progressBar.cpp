#include <windows.h>
#include <windowsx.h>
#include "resource.h"
#include <CommCtrl.h> 

//输出消息到Debug控制台
void print(LPCWSTR format, ...)
{
	WCHAR buff[100];
	va_list ap;
	va_start(ap, format);
	wvsprintfW(buff, format, ap);
	va_end(ap);
	OutputDebugStringW(buff);
}

INT_PTR Dlgproc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	HINSTANCE hInstance = GetModuleHandleW(0);

	switch (uMsg)
	{
	case WM_INITDIALOG:
	{
		SendDlgItemMessageW(hWnd, IDC_PROGRESS1, PBM_SETRANGE, 0, MAKELPARAM(0, 100));
		SendDlgItemMessageW(hWnd, IDC_PROGRESS1, PBM_SETPOS, 50, 0);

		SendDlgItemMessageW(hWnd, IDC_SLIDER1, TBM_SETRANGE, TRUE, MAKELPARAM(0, 100));
		SendDlgItemMessageW(hWnd, IDC_SLIDER1, TBM_SETPOS, TRUE, 50);
		break;
	}
	case WM_CLOSE:
	{

		EndDialog(hWnd, 0);
		//DestroyWindow(hWnd);
		//PostQuitMessage(0);
		//ExitWindows(0);
	}
	
	case WM_HSCROLL:
	{
		if (GetDlgItem(hWnd, IDC_SLIDER1) == (HWND)lParam)
		{
			int pos = SendDlgItemMessageW(hWnd, IDC_SLIDER1, TBM_GETPOS, 0, 0);
			SendDlgItemMessageW(hWnd, IDC_PROGRESS1, PBM_SETPOS, pos, 0);
		}
		break;
	}
	default:
		return FALSE;
	}
	return TRUE;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	DialogBoxW(hInstance, MAKEINTRESOURCEW(IDD_DIALOG1), NULL, Dlgproc);

	return 0;
}