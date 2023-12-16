#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	while (1)
	{
		printf("How are you?\n");
	}
	

	return 0;
}

int main(void)
{

	//HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, NULL, 0, NULL);
	//WaitForSingleObject(hThread, INFINITE);

	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);

	THREADENTRY32 threadEntry{ sizeof(THREADENTRY32) };
	BOOL success = Thread32First(hSnapshot, &threadEntry);

	if (success)
	{
		
		do
		{
			if (threadEntry.th32OwnerProcessID == 20684)
			{
				//��ȡһ���Դ��ڵ��߳̾��
				HANDLE hThread = OpenThread(THREAD_ALL_ACCESS, NULL, threadEntry.th32ThreadID);

				//��ͣ�߳�
				//SuspendThread(hThread);

				//�ָ��߳�
				ResumeThread(hThread);

				CloseHandle(hThread);
			}
			//printf("�߳�ID:%d\n", threadEntry.th32ThreadID);

		} while (Thread32Next(hSnapshot, &threadEntry));
	}

	return 0;
}