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
	
	//�ҵ���Ϸ���̲���
	HWND hWnd = FindWindowA(NULL, winName);
	if (hWnd == 0)
	{
		MessageBoxA(0, "�Ҳ�����Ϸ����", "��ʾ", MB_OK);
		return 0;
	}
	GetWindowThreadProcessId(hWnd, &pid);
	if (pid == 0)
	{
		MessageBoxA(0, "��ȡ����IDʧ��", "��ʾ", MB_OK);
		return 0;
	}
	HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	//����Զ���ڴ�ռ�
	char* allocAddr = (char*)VirtualAllocEx(hProcess, 0, 0X100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
	//�ҵ������������޸���ش���
	DWORD oldProtect = 0;
	DWORD offset = 0;
	//ƫ�� = Ŀ���ַ - (��ǰ��ַ + jmpָ���С)
	offset = (DWORD)allocAddr - (attackAddr + 5);
	memcpy(&hookCode[1], &offset, 4);

	VirtualProtectEx(hProcess, (char*)attackAddr, 8, PAGE_EXECUTE_READWRITE, &oldProtect);
	DWORD realWrite = 0;
	WriteProcessMemory(hProcess, (char*)attackAddr, hookCode, 8, &realWrite);
	VirtualProtectEx(hProcess, (char*)attackAddr, 8, oldProtect, &oldProtect);

	//ʵ���޵��߼�����
	char allocFunc[] = { 0X56, 0X8B, 0XF1, 0X57, 0X81, 0X7E, 0X04, 0X02, 0X00,
		0X00, 0X00, 0X75, 0X08, 0XC7, 0X44, 0X24, 0X0C, 0X00, 0X00, 0X00, 0X00,
		0XE9, 0X00, 0X00, 0X00, 0X00 };
	
	DWORD offset2 = (attackAddr + 8) - ((DWORD)allocAddr + 26);
	memcpy(&allocFunc[22], &offset2, 4);
	WriteProcessMemory(hProcess, allocAddr, allocFunc, 26, &realWrite);
	system("pause");
	return 0;
}