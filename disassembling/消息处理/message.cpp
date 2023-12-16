#include <windows.h>
#include <stdio.h>

void print(LPCWSTR format,...)
{
	WCHAR buff[100]{ 0 };
	va_list ap;
	va_start(ap, format);
	wvsprintfW(buff, format, ap);
	va_end(ap);
	OutputDebugStringW(buff);
	
}
LRESULT CALLBACK WinProc2(
	HWND hwnd,
	UINT uMsg,
	WPARAM wParam,
	LPARAM lParam
)
{
	switch (uMsg)
	{
	case WM_CREATE: 
	{
		MessageBoxW(hwnd, L"窗口创建了", L"提示", MB_OK);
		break;
	}
	case WM_CLOSE: 
	{
		MessageBoxW(hwnd, L"窗口关闭了", L"提示", MB_OK);
		DestroyWindow(hwnd);
		//PostQuitMessage(0);
		ExitProcess(0);
		break;
	}
		
	case WM_MOUSEMOVE:
	{
		WORD x = LOWORD(lParam);
		WORD y = HIWORD(lParam);
		print(L"鼠标移动了!X=%d, y=%d\n", x, y);
		SendMessageW(hwnd, WM_USER, wParam, lParam);
		break;
	}
	case WM_LBUTTONDOWN:
	{
		print(L"鼠标点击了，关闭QQ窗口\n");
		SendMessageW((HWND)0X0022056A, WM_CLOSE, wParam, lParam);
		ExitProcess(0);
		break;
	}
	case WM_USER:
	{
		print(L"自定义消息\n");
		break;
	}
	default:
		break;
	}
	
	return DefWindowProc(hwnd, uMsg, wParam, lParam);;
}

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow
)
{
	TCHAR szname[] = TEXT("classname");
	HWND hwnd;
	MSG msg;

	//1.创建窗口类
	WNDCLASS wndclass = { 0 };
	wndclass.lpfnWndProc = WinProc2;
	wndclass.lpszClassName = szname;
	
	//2.注册窗口类
	RegisterClassW(&wndclass);

	//3.创建窗口
	hwnd = CreateWindowW(
		szname,
		TEXT("HELLO"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		0,
		CW_USEDEFAULT,
		0,
		NULL,
		NULL,
		hInstance,
		0
	);
	//4.显示窗口
	if (hwnd)
	{
		ShowWindow(hwnd, SW_SHOW);
	}
	else 
	{
		MessageBoxW(hwnd, L"窗口创建失败", L"窗口", MB_OK);
		ExitProcess(0);
	}
	
	//5.获取消息
	
	while (GetMessageW(&msg, hwnd, 0, 0))
	{
		//TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}
	

	return 0;

}
