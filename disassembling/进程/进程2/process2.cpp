#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

int main(void)
{
	//����������������
	setlocale(LC_ALL, "chs");

	//��һ�����̻�ȡ���̾��
	HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 15588);
	//����һ������
	TerminateProcess(hprocess, 0);

	//��������
	HANDLE hSnopshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W	pEntry{ sizeof(PROCESSENTRY32W) };
	//��ȡ��һ��
	BOOL pSuccess = Process32First(hSnopshot, &pEntry);
	if (pSuccess) {
		do {
			printf("����id:%d, ��������:%ls\n", pEntry.th32ProcessID, pEntry.szExeFile);
		} while (Process32Next(hSnopshot, &pEntry));
	}

	//����ģ��
	HANDLE hSnopshot2 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 3556);
	MODULEENTRY32W mEntry{ sizeof(MODULEENTRY32W) };
	BOOL mSuccess = Module32FirstW(hSnopshot2, &mEntry);
	if (mSuccess) {
		do {
			printf("ģ������:%ls\n", mEntry.szExePath);
		} while (Module32NextW(hSnopshot2, &mEntry));
	}
	return 0;
}