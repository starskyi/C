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

void insertColumn(HWND hWnd, int fmt, int cx, LPWSTR pszText, int index)
{
	LVCOLUMNW lvColumn = { LVCF_FMT | LVCF_WIDTH | LVCF_TEXT };
	lvColumn.fmt = fmt;
	lvColumn.cx = cx;
	lvColumn.pszText = pszText;

	SendDlgItemMessageW(hWnd, IDC_LIST1, LVM_INSERTCOLUMN, index, (LPARAM)&lvColumn);
}

void insertItem(HWND hWnd, int nRow)
{
	LVITEMW lvItem = { LVIF_TEXT, nRow };
	lvItem.pszText = (LPWSTR)L"";
	SendDlgItemMessageW(hWnd, IDC_LIST1, LVM_INSERTITEM, 0, (LPARAM)&lvItem);
	
}


void SetListItemText(HWND hWnd,LPWSTR pszText ,int nRow, int nColumn)
{
	LVITEMW lvItem = { LVIF_TEXT, nRow, nColumn};
	lvItem.pszText = (LPWSTR)pszText;

	SendDlgItemMessageW(hWnd, IDC_LIST1, LVM_SETITEMTEXT, nRow, (LPARAM)&lvItem);
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
		ListView_SetExtendedListViewStyle(GetDlgItem(hWnd, IDC_LIST1), LVS_EX_FULLROWSELECT|LVS_EX_GRIDLINES);
		insertColumn(hWnd, LVCFMT_CENTER, 100, (LPWSTR)L"名称", 0);
		insertColumn(hWnd, LVCFMT_CENTER, 100, (LPWSTR)L"PID", 1);
		insertColumn(hWnd, LVCFMT_CENTER, 100, (LPWSTR)L"状态", 2);
		insertColumn(hWnd, LVCFMT_CENTER, 100, (LPWSTR)L"用户名", 3);
		insertColumn(hWnd, LVCFMT_CENTER, 100, (LPWSTR)L"CPU", 4);
		
		insertItem(hWnd, 0);
		SetListItemText(hWnd, (LPWSTR)L"1.exe", 0, 0);
		SetListItemText(hWnd, (LPWSTR)L"2.exe", 0, 1);
		SetListItemText(hWnd, (LPWSTR)L"3.exe", 0, 2);
		SetListItemText(hWnd, (LPWSTR)L"4.exe", 0, 3);
		SetListItemText(hWnd, (LPWSTR)L"5.exe", 0, 4);
		insertItem(hWnd, 1);
		SetListItemText(hWnd, (LPWSTR)L"6.exe", 1, 0);
		SetListItemText(hWnd, (LPWSTR)L"7.exe", 1, 1);
		SetListItemText(hWnd, (LPWSTR)L"8.exe", 1, 2);
		SetListItemText(hWnd, (LPWSTR)L"9.exe", 1, 3);
		SetListItemText(hWnd, (LPWSTR)L"10.exe", 1, 4);
		
		
		
		
		break;
	}
	case WM_CLOSE:
	{

		EndDialog(hWnd, 0);
	}
	case WM_NOTIFY:
	{

		NMLISTVIEW* listItem = (NMLISTVIEW*)lParam;
		if (wParam == IDC_LIST1 && ((NMHDR*)lParam)->code == NM_CLICK && listItem->iItem != -1)
		{
			WCHAR text[100]{ 0 };
			
			LVITEM tag{ 0 };
			tag.iSubItem = listItem->iSubItem;
			tag.pszText = text;
			tag.cchTextMax = 100;
			SendDlgItemMessageW(hWnd, IDC_LIST1, LVM_GETITEMTEXTW, listItem->iItem, (LPARAM)&tag);
			MessageBoxW(hWnd, text, L"消息", 0);
		}
		else if(wParam == IDC_LIST1 && ((NMHDR*)lParam)->code == NM_CLICK)
		{
			POINT point{ 0 };
			GetCursorPos(&point);
			HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCEW(IDR_MENU1));
			HMENU subMenu = GetSubMenu(hMenu, 0);
			TrackPopupMenu(subMenu, TPM_LEFTALIGN, point.x, point.y, 0, hWnd, 0);
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