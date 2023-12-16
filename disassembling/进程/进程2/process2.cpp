#include <Windows.h>
#include <iostream>
#include <TlHelp32.h>

int main(void)
{
	//设置语言允许中文
	setlocale(LC_ALL, "chs");

	//打开一个进程获取进程句柄
	HANDLE hprocess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, 15588);
	//结束一个进程
	TerminateProcess(hprocess, 0);

	//遍历进程
	HANDLE hSnopshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32W	pEntry{ sizeof(PROCESSENTRY32W) };
	//获取第一个
	BOOL pSuccess = Process32First(hSnopshot, &pEntry);
	if (pSuccess) {
		do {
			printf("进程id:%d, 进程名称:%ls\n", pEntry.th32ProcessID, pEntry.szExeFile);
		} while (Process32Next(hSnopshot, &pEntry));
	}

	//遍历模块
	HANDLE hSnopshot2 = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, 3556);
	MODULEENTRY32W mEntry{ sizeof(MODULEENTRY32W) };
	BOOL mSuccess = Module32FirstW(hSnopshot2, &mEntry);
	if (mSuccess) {
		do {
			printf("模块名称:%ls\n", mEntry.szExePath);
		} while (Module32NextW(hSnopshot2, &mEntry));
	}
	return 0;
}