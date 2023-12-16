#include <windows.h>
#include "resource.h"

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
	switch (uMsg)
	{
		case WM_INITDIALOG:
		{
			SendDlgItemMessageW(hWnd, IDC_CHECK1, BM_SETCHECK, BST_CHECKED, 0);
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
			WORD btnID = LOWORD(wParam);
			WCHAR name[20]{ 0 };
			print(L"%d\n", btnID);
			switch (btnID)
			{
				
				case IDC_BUTTON2:
				{
					

					for (UINT btn = 1004; btn <= 1006; btn++)
					{
						
						GetDlgItemTextW(hWnd, btn, name, 20);
						UINT status = SendDlgItemMessageW(hWnd, btn, BM_GETCHECK, 0, 0);
						print(L"%s\n", name);
						if (status == BST_CHECKED) {
							MessageBoxW(hWnd, name, L"提示", MB_OK);
						}
					}
					break;
				}
				case IDC_BUTTON3:
				{
					for (UINT btn = 1004; btn <= 1006; btn++)
					{
						GetDlgItemTextW(hWnd, btn, name, 20);
						UINT status = SendDlgItemMessageW(hWnd, btn, BM_GETCHECK, 0, 0);
						if (status == BST_CHECKED) {
							MessageBoxW(hWnd, name, L"提示", MB_OK);
						}
					}
					break;
				}
				default:
					break;
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