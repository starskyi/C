#include <Windows.h>

int main(void)
{
	HANDLE hMailslot = CreateFile(L"\\\\.\\mailslot\\MailslotTest", GENERIC_WRITE, FILE_SHARE_READ, NULL, 
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	
	if (hMailslot == INVALID_HANDLE_VALUE) {
		MessageBox(0, L"打开邮槽失败", L"提示", MB_OK);
		return 0;
	}

	WCHAR buff[] = L"Hello World";
	WriteFile(hMailslot, buff, 24, NULL, NULL);
	CloseHandle(hMailslot);
	return 0;
}