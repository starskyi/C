#include <Windows.h>
#include <iostream>

//�������ݵĻ�����
CHAR buff1[0x100]{ 0 };
CHAR buff2[0x100]{ 0 };

//�ص�����
void WINAPI overlappedCompletionRoutine(
	DWORD dwErrorCode,
	DWORD dwNumberOfBytesTransferred,
	LPOVERLAPPED lpOverlapped
)
{
	if (lpOverlapped->hEvent == (HANDLE)0X101)
	{
			printf("Hello World %s\n", buff1);
	}
	else {
			printf("How are you %s\n", buff2);
	}
}

int main(void)
{
	//���ļ�,ʹ���첽IO
	HANDLE hFile = CreateFile(L"test.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, 
		OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

	//�첽����
	OVERLAPPED overlapped1{ 0 };
	OVERLAPPED overlapped2{ 0 };

	//ָ���¼�,������ʶ�ĸ��߳�
	overlapped1.hEvent = (HANDLE)0X101;
	overlapped2.hEvent = (HANDLE)0X102;

	//��ȡ�ļ�
	ReadFileEx(hFile, buff1, 0X100, &overlapped1, overlappedCompletionRoutine);
	ReadFileEx(hFile, buff2, 0X100, &overlapped2, overlappedCompletionRoutine);
	
	printf("Welcome\n");

	//�������̣߳��ȴ����������������
	SleepEx(0, TRUE);

	//�رվ��
	CloseHandle(hFile);

	return 0;
}