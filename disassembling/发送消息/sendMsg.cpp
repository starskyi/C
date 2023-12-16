#include <Windows.h>

int main(void)
{
	HWND hwnd = FindWindow(NULL, L"Dialog");
	COPYDATASTRUCT sendData{ 0 };
	sendData.cbData = 24;
	sendData.lpData = (PVOID)L"ÄãºÃ´óË§±È";
	SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&sendData);

	return 0;
}