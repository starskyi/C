#include <Windows.h>

int main(void)
{
	HWND hwnd = FindWindow(NULL, L"Dialog");
	COPYDATASTRUCT sendData{ 0 };
	sendData.cbData = 24;
	sendData.lpData = (PVOID)L"��ô�˧��";
	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&sendData);

	return 0;
}