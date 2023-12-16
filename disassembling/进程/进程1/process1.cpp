#include <Windows.h>

int main(void)
{
	STARTUPINFO sw{ 0 };
	PROCESS_INFORMATION pInfo{ 0 };

	//创建一个进程
	CreateProcessW(
		L"D:\\code\\click.exe", //进程路径
		NULL,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&sw,
		&pInfo
	);
	CloseHandle(pInfo.hThread);
	CloseHandle(pInfo.hProcess);

	return 0;
}