#include <Windows.h>
#include <string.h>
#include <iostream>
int main(void)
{
	char winName[100] = "Sword2 Window";
	DWORD pid = 0;
	DWORD baseAddr = 0;
	DWORD attackAddr = 0X41FD40;
	char hookCode[8] = { 0xE9, 0X00, 0X00, 0X00, 0X00, 0x90, 0X90, 0X90};
	
	//找到游戏进程并打开
	HWND hWnd = FindWindowA(NULL, winName);
	if (hWnd == 0)
	{
		MessageBoxA(0, "找不到游戏窗口", "提示", MB_OK);
		return 0;
	}
	GetWindowThreadProcessId(hWnd, &pid);
	if (pid == 0)
	{
		MessageBoxA(0, "获取进程ID失败", "提示", MB_OK);
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	//申请远程内存空间
	char* allocAddr = (char*)VirtualAllocEx(hProcess, 0, 0X100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	//找到攻击函数，修改相关代码
	DWORD oldProtect = 0;
	DWORD offset = 0;
	//偏移 = 目标地址 - (当前地址 + jmp指令大小)
	offset = (DWORD)allocAddr - (attackAddr + 5);
	memcpy(&hookCode[1], &offset, 4);

	VirtualProtectEx(hProcess, (char*)attackAddr, 8, PAGE_EXECUTE_READWRITE, &oldProtect);
	DWORD realWrite = 0;
	WriteProcessMemory(hProcess, (char*)attackAddr, hookCode, 8, &realWrite);
	VirtualProtectEx(hProcess, (char*)attackAddr, 8, oldProtect, &oldProtect);

	//实现无敌逻辑代码
	char allocFunc[] = { 0X56, 0X8B, 0XF1, 0X57, 0X81, 0X7E, 0X04, 0X02, 0X00,
		0X00, 0X00, 0X75, 0X08, 0XC7, 0X44, 0X24, 0X0C, 0X00, 0X00, 0X00, 0X00,
		0XE9, 0X00, 0X00, 0X00, 0X00 };
	
	DWORD offset2 = (attackAddr + 8) - ((DWORD)allocAddr + 26);
	memcpy(&allocFunc[22], &offset2, 4);
	WriteProcessMemory(hProcess, allocAddr, allocFunc, 26, &realWrite);
	system("pause");
	return 0;
}