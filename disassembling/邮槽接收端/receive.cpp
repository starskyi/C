#include <Windows.h>

int main(void)
{
	HANDLE hMailslot = CreateMailslot(L"\\\\.\\mailslot\\MailslotTest", 100, MAILSLOT_WAIT_FOREVER, NULL);

	if (hMailslot == INVALID_HANDLE_VALUE)
	{
		MessageBox(0, L"�����ʲ�ʧ��", L"��ʾ", MB_OK);
		return 0;
	}

	WCHAR buff[50]{ 0 };
	DWORD readSize{ 0 };

	ReadFile(hMailslot, buff, 100, &readSize, NULL);
	MessageBox(0, buff, L"��Ϣ", MB_OK);
	CloseHandle(hMailslot);
	return 0;
}