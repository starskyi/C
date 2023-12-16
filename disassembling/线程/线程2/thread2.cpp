#include <Windows.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	FILETIME createTime{ 0 };
	FILETIME exitTime{ 0 };
	FILETIME kernelTime{ 0 };
	FILETIME userTime{ 0 };

	GetThreadTimes(lpParameter, &createTime, &exitTime, &kernelTime, &userTime);

	FILETIME localFileTime{ 0 };
	SYSTEMTIME systemTime{ 0 };
	FileTimeToLocalFileTime(&createTime, &localFileTime);
	FileTimeToSystemTime(&localFileTime, &systemTime);


	return 0;
}

int main(void)
{
	HANDLE hCurrent = GetCurrentThread();

	FILETIME createTime{ 0 };
	FILETIME exitTime{ 0 };
	FILETIME kernelTime{ 0 };
	FILETIME userTime{ 0 };

	GetThreadTimes(hCurrent, &createTime, &exitTime, &kernelTime, &userTime);

	FILETIME localFileTime{ 0 };
	SYSTEMTIME systemTime{ 0 };
	FileTimeToLocalFileTime(&createTime, &localFileTime);
	FileTimeToSystemTime(&localFileTime, &systemTime);

	HANDLE newHandle{ 0 };

	DuplicateHandle(
		GetCurrentProcess(),
		hCurrent,
		GetCurrentProcess(),
		&newHandle,
		NULL,
		NULL,
		DUPLICATE_SAME_ACCESS
	);

	HANDLE hThread2 = CreateThread(NULL, NULL, ThreadProc, newHandle, 0, NULL);

	WaitForSingleObject(hThread2, INFINITE);
	return 0;
}