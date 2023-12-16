#include <Windows.h>
#include <iostream>

int main(void)
{
	
	HANDLE hSemaphore;
	hSemaphore = OpenSemaphoreW(EVENT_ALL_ACCESS, NULL, L"star");

	if (!hSemaphore)
	{
		hSemaphore = CreateSemaphoreW(NULL, 0, 3, L"star");
	}

	BOOL success = ReleaseSemaphore(hSemaphore, 1, NULL);
	if (!success)
	{
		MessageBox(0, L"�����ʧ���������ܳ���3��!", L"ERROR", MB_OK);
		return 0;
	}
	system("pause");
	CloseHandle(hSemaphore);
	return 0;
}