#include <Windows.h>
#include <iostream>
int main(void)
{
	char fileName[100];
	int pid = 0;
	printf("Please input fileName:");
	gets_s(fileName, 100);
	printf("please input PID:");
	scanf_s("%d", &pid);
	printf("%s %d\n", fileName, pid);
	system("pause");
	DWORD buffSize = strlen(fileName) + 1;
	SIZE_T realWrite = 0;

	//1.��Ŀ�����
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	//2.����Զ���ڴ�ռ�
	char *str = (char*)VirtualAllocEx(hProcess, 0, buffSize, MEM_COMMIT, PAGE_READWRITE);

	//3.��DLL�ļ�д�뵽Զ�̽��̵��ڴ�
	WriteProcessMemory(hProcess, str, fileName, buffSize, &realWrite);

	//����Զ���߳�
	HANDLE hThread = CreateRemoteThread(hProcess, 0, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, str, 0, 0);

	WaitForSingleObject(hThread, -1);
	VirtualFreeEx(hProcess, str, 0, MEM_RELEASE);
	CloseHandle(hThread);
	CloseHandle(hProcess);
	return 0;
}