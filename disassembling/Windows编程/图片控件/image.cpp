#include <windows.h>
#include "resource.h"
#include <windowsx.h>

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
		//设置图片
		HBITMAP image = LoadBitmap(hInstance, MAKEINTRESOURCEW(IDB_BITMAP1));
		SendDlgItemMessageW(hWnd, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LONG)image);

		//设置下拉框选项
		ComboBox_AddString(GetDlgItem(hWnd, IDC_COMBO1), L"图片1");
		ComboBox_AddString(GetDlgItem(hWnd, IDC_COMBO1), L"图片2");

		ComboBox_SetCurSel(GetDlgItem(hWnd, IDC_COMBO1), 0);

		break;
	}
	case WM_CLOSE:
	{

		EndDialog(hWnd, 0);
		//DestroyWindow(hWnd);
		//PostQuitMessage(0);
		//ExitWindows(0);
	}
	case WM_COMMAND:
	{
		WORD controlID = LOWORD(wParam);
		WORD msgType = HIWORD(wParam);

		switch (controlID)
		{
			case IDC_COMBO1:
			{
				if (msgType == CBN_SELCHANGE)
				{
					int index = ComboBox_GetCurSel(GetDlgItem(hWnd, IDC_COMBO1));

					HBITMAP image = LoadBitmap(hInstance, MAKEINTRESOURCEW(IDB_BITMAP1 + index));
					SendDlgItemMessageW(hWnd, IDC_STATIC1, STM_SETIMAGE, IMAGE_BITMAP, (LONG)image);
				}
			}
		}


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