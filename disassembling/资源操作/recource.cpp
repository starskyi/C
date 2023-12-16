#include <Windows.h>
#include <commCtrl.h>
#include <iostream>
#include <string.h>
#include "resource.h"
//�����Ϣ��Debug����̨
void print(LPCWSTR format, ...)
{
	WCHAR buff[100];
	va_list ap;
	va_start(ap, format);
	wvsprintfW(buff, format, ap);
	va_end(ap);
	OutputDebugStringW(buff);
}


LRESULT CALLBACK WndProc(
	HWND hWnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	HINSTANCE hInstance = GetModuleHandleW(0);
	switch (uMsg)
	{
		case WM_CREATE:
		{
			//��ӿؼ�
			CreateWindowW(WC_BUTTON, L"����ͼ��", WS_CHILD | WS_VISIBLE, 10, 5, 120, 30, hWnd, (HMENU)0X001, NULL, NULL);
			CreateWindowW(WC_BUTTON, L"���ù��", WS_CHILD | WS_VISIBLE, 10, 40, 120, 30, hWnd, (HMENU)0X002, NULL, NULL);
			CreateWindowW(WC_BUTTON, L"���ò˵�", WS_CHILD | WS_VISIBLE, 10, 80, 120, 30, hWnd, (HMENU)0X003, NULL, NULL);
			CreateWindowW(WC_BUTTON, L"���ø�����", WS_CHILD | WS_VISIBLE, 10, 120, 120, 30, hWnd, (HMENU)0X004, NULL, NULL);
			CreateWindow(WC_EDIT, L"�����봰�ڱ���", WS_CHILD | WS_VISIBLE | WS_BORDER, 10, 160, 200, 150, hWnd, (HMENU)0X005, NULL, NULL);

			//HWND textBox = GetDlgItem(hWnd, 0x005);
			//SetWindowTextW(textBox, L"myWindows");
			SetDlgItemTextW(hWnd, 0x005, L"myWindows");
			break;
		}
		case WM_RBUTTONDOWN:
		{
			POINT point;
			GetCursorPos(&point);
			HMENU hMenu = LoadMenuW(hInstance, MAKEINTRESOURCEW(IDR_MENU1));
			HMENU hSubMenu = GetSubMenu(hMenu, 0);
			TrackPopupMenu(hSubMenu, TPM_LEFTALIGN, point.x, point.y, 0, hWnd, NULL);
			break;
		}
		case WM_CLOSE:
		{
			//MessageBoxW(hWnd, L"���ڹر���", L"tip", MB_OK);
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			ExitProcess(0);
			break;
		}
		case WM_COMMAND:
		{


			WORD crlId = LOWORD(wParam);
			print(L"%03d\n", crlId);
			switch (crlId)
			{
				case 0x001:
				{

			
					HICON hIcon = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_ICON1));
					SetClassLongPtr(hWnd, GCLP_HICON, (LONG)hIcon);
			
					break;
				}
				case 0x002:
				{
					HCURSOR hCursor = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_ICON1));
					SetClassLongPtr(hWnd, GCLP_HCURSOR, (LONG)hCursor);

					break;
				}
				case 0x003:
				{
					HMENU hMenu = LoadMenuW(hInstance, MAKEINTRESOURCEW(IDR_MENU1));
			
					SetMenu(hWnd, hMenu);
					break;
				}
				case 0x004:
				{
					WCHAR buff[100];
					GetDlgItemTextW(hWnd, 0x005, buff, 100);
					HWND hwnd = FindWindowW(NULL, buff);
					SetParent((HWND)lParam, hwnd);
					break;
				}
				case ID_40001:
				{
					MessageBoxW(hWnd, L"���ļ�", L"��Ϣ", MB_OK);
					break;
				}
				case ID_40002:
				{
					MessageBoxW(hWnd, L"�����ļ�", L"��Ϣ", MB_OK);
					break;
				}
				case ID_40003:
				{
					MessageBoxW(hWnd, L"�½�", L"��Ϣ", MB_OK);
					break;
				}
				default:
					break;
			}

		}
		default:
			break;
	}
	return DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInstance, LPSTR lpCmdLine, int nShowCmd)
{
	srand(time(NULL));
	HWND hWnd;
	MSG msg;
	LPCWSTR wndClassName = L"mywndclass";

	//1.����������
	WNDCLASS wndClass = { 0 };
	wndClass.lpszClassName = wndClassName;
	wndClass.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wndClass.lpfnWndProc = WndProc;
	//wndClass.hIcon = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_ICON1));
	//wndClass.hCursor = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_ICON1));
	//wndClass.lpszMenuName = MAKEINTRESOURCEW(IDR_MENU1);
	
	//HMENU hMenu = LoadMenuW(hInstance, MAKEINTRESOURCEW(IDR_MENU1));

	//2.ע�ᴰ����
	RegisterClassW(&wndClass);

	//3.��������
	hWnd = CreateWindowW(
		wndClassName,
		L"myWindows",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		hInstance,
		0);
	//4.��ʾ����
	if (hWnd) {
		ShowWindow(hWnd, SW_SHOWNORMAL);
	}
	else
	{
		MessageBoxW(NULL, L"��������ʧ��", L"error", MB_OK);
	}

	//5.��ȡ��Ϣ�ַ���Ϣ
	while (GetMessageW(&msg, hWnd, 0, 0)) {
		TranslateMessage(&msg);//��������Ϣ�����ı���, ���ע�͵��ı��򽫲��ɱ༭
		DispatchMessageW(&msg);
	}

	return 0;
}