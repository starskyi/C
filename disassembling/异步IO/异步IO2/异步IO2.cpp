#include <Windows.h>
#include <iostream>

//接收内容的缓冲区
CHAR buff1[0x100]{ 0 };
CHAR buff2[0x100]{ 0 };

//回调函数
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
	//打开文件,使用异步IO
	HANDLE hFile = CreateFile(L"test.txt", GENERIC_READ | GENERIC_WRITE, NULL, NULL, 
		OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);

	//异步对象
	OVERLAPPED overlapped1{ 0 };
	OVERLAPPED overlapped2{ 0 };

	//指定事件,用来标识哪个线程
	overlapped1.hEvent = (HANDLE)0X101;
	overlapped2.hEvent = (HANDLE)0X102;

	//读取文件
	ReadFileEx(hFile, buff1, 0X100, &overlapped1, overlappedCompletionRoutine);
	ReadFileEx(hFile, buff2, 0X100, &overlapped2, overlappedCompletionRoutine);
	
	printf("Welcome\n");

	//挂起主线程，等待其他进程运行完毕
	SleepEx(0, TRUE);

	//关闭句柄
	CloseHandle(hFile);

	return 0;
}