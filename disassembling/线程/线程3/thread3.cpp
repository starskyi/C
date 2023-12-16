#include <Windows.h>
#include <stdio.h>

LONG count = 0;
BOOL flag[2];
int turn = 0;
int size = 10000;
HANDLE hCritical;
CRITICAL_SECTION criticalSection{ 0 };

DWORD WINAPI ThreadProc1(LPVOID lpParameter)
{
	
	for (int i = 0; i < size; i++) {

		//������ʷ���һ,������
		/*flag[0] = TRUE;
		turn = 1;
		while (flag[1] && turn == 1);
		count++;
		flag[0] = FALSE;*/

		//������
		//InterlockedIncrement(&count);

		//������
		/*EnterCriticalSection(&criticalSection);
		count++;
		LeaveCriticalSection(&criticalSection);*/

		//������
		WaitForSingleObject(hCritical, -1);
		count++;
		ReleaseMutex(hCritical);
	}
	
	return 0;
}

DWORD WINAPI ThreadProc2(LPVOID lpParameter)
{
	
	for (int i = 0; i < size; i++)
	{
		//������ʷ���һ,������
		/*flag[1] = TRUE;
		turn = 0;
		while (flag[0] && turn == 0);
		count++;
		flag[1] = FALSE;*/

		//������
		//InterlockedIncrement(&count);


		/*EnterCriticalSection(&criticalSection);
		count++;
		LeaveCriticalSection(&criticalSection);*/

		//������
		WaitForSingleObject(hCritical, -1);
		count++;
		ReleaseMutex(hCritical);

	}
	
	return 0;
}
int main(void)
{

	
	for (int i = 0; i < 20; i++) {
	
		count = 0;

		InitializeCriticalSection(&criticalSection);
		HANDLE thread1 = CreateThread(NULL, NULL, ThreadProc1, NULL, 0, NULL);
		HANDLE thread2 = CreateThread(NULL, NULL, ThreadProc2, NULL, 0, NULL);

		hCritical =  CreateMutex(NULL, NULL, L"star");
		WaitForSingleObject(thread1, INFINITE);
		WaitForSingleObject(thread2, INFINITE);

		CloseHandle(thread1);
		CloseHandle(thread2);
		
		DeleteCriticalSection(&criticalSection);
		printf("%d\n", count);
	}
	

	return 0;
}