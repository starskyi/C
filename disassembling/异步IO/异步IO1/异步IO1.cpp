#include <Windows.h>
#include <iostream>

int main(void)
{
	//���ļ���ʹ���첽
	HANDLE hFile = CreateFile(L"test.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_FLAG_OVERLAPPED, NULL);
	
	CHAR buff[0X100]{ 0 };
	OVERLAPPED overlapped{ 0 };

	ReadFile(hFile, buff, 0X100, NULL, &overlapped);
	WaitForSingleObject(hFile, -1);

	DWORD numberOfBytes = 0;
	GetOverlappedResult(hFile, &overlapped, &numberOfBytes, FALSE);

	printf("�ļ�����:%s\n", buff);
	printf("ʵ�ʶ�ȡ����:%d\n", numberOfBytes);
	CloseHandle(hFile);
	
	return 0;
}