// MySwordPlug.cpp: 实现文件

#include "MySwordPlug.h"
#include "resource.h"
#include "afxdialogex.h"
// MySwordPlug 对话框

IMPLEMENT_DYNAMIC(MySwordPlug, CDialogEx)

MySwordPlug::MySwordPlug(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{
	//SetIcon(AfxGetApp()->LoadIcon(IDI_ICON1), FALSE);
}

MySwordPlug::~MySwordPlug()
{
	if (allocAddr != NULL)
	{
		VirtualFreeEx(hProcess, allocAddr, 0, MEM_RELEASE);
		allocAddr = NULL;
	}
	if (hpAllocAddr != NULL)
	{
		VirtualFreeEx(hProcess, hpAllocAddr, 0, MEM_RELEASE);
		hpAllocAddr = NULL;
	}
	if (autoHpFlag != NULL)
	{
		VirtualFreeEx(hProcess, autoHpFlag, 0, MEM_RELEASE);
		autoHpFlag = NULL;
	}
}

void MySwordPlug::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, invincibleBox);
	DDX_Control(pDX, IDC_CHECK2, autoHp);
	DDX_Control(pDX, IDC_CHECK3, autoCast);
}


BEGIN_MESSAGE_MAP(MySwordPlug, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &MySwordPlug::Invincible)
	ON_BN_CLICKED(IDC_CHECK2, &MySwordPlug::AutoHP)
	ON_BN_CLICKED(IDC_CHECK3, &MySwordPlug::AutoCast)
END_MESSAGE_MAP()


// MySwordPlug 消息处理程序


void MySwordPlug::Invincible()
{
	DWORD realWrite = 0;
	DWORD oldProtect = 0;

	if (hProcess == 0)
	{
		return;
	}

	int status = invincibleBox.GetCheck();
	if (status)
	{
		//开启无敌
		//申请远程内存空间
		allocAddr = (char*)VirtualAllocEx(hProcess, 0, 0X100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (allocAddr == NULL)
		{
			return;
		}

		//实现无敌逻辑代码
		
		DWORD offset2 = (attackAddr + 8) - ((DWORD)allocAddr + 26);
		memcpy(&allocFunc[22], &offset2, 4);
		DWORD realWrite = 0;
		BOOL result = WriteProcessMemory(hProcess, allocAddr, allocFunc, 26, &realWrite);

		//找到攻击函数，修改相关代码
		
		DWORD offset = 0;
		//偏移 = 目标地址 - (当前地址 + jmp指令大小)
		offset = (DWORD)allocAddr - (attackAddr + 5);
		memcpy(&hookCode[1], &offset, 4);

		VirtualProtectEx(hProcess, (char*)attackAddr, 8, PAGE_EXECUTE_READWRITE, &oldProtect);
		WriteProcessMemory(hProcess, (char*)attackAddr, hookCode, 8, &realWrite);
		VirtualProtectEx(hProcess, (char*)attackAddr, 8, oldProtect, &oldProtect);
	}
	else 
	{
		//关闭无敌
		VirtualProtectEx(hProcess, (char*)attackAddr, 8, PAGE_EXECUTE_READWRITE, &oldProtect);
		WriteProcessMemory(hProcess, (char*)attackAddr, oldCode, 8, &realWrite);
		VirtualProtectEx(hProcess, (char*)attackAddr, 8, oldProtect, &oldProtect);
		if (allocAddr != NULL)
		{
			VirtualFreeEx(hProcess, allocAddr, 0, MEM_RELEASE);
			allocAddr = NULL;
		}
		
	}
}

//实现无敌
BOOL MySwordPlug::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	
	//找到游戏进程并打开
	HWND hWnd = FindWindowA(NULL, winName);
	if (hWnd == 0)
	{
		MessageBoxA(0, "找不到游戏窗口", "提示", MB_OK);
		return FALSE;
	}
	GetWindowThreadProcessId(hWnd, &pid);
	if (pid == 0)
	{
		MessageBoxA(0, "获取进程ID失败", "提示", MB_OK);
		return FALSE;
	}
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
	if (hProcess == 0)
	{
		return FALSE;
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//自动回血函数
DWORD _stdcall autoHpFunc(LPVOID lParam)
{
	DWORD* hp = (DWORD*)0X4CE61C;
	while (*(int*)lParam)
	{
		
		if (*hp <= 600)
		{
			_asm 
			{
				push 0x52
				mov ecx, 0x00537400
				mov eax,0x004252E0
				call eax
			}
		}
	}
}

HANDLE remoteThread = 0;
//实现自动回血
void MySwordPlug::AutoHP()
{
	// TODO: 在此添加控件通知处理程序代码
	if (hProcess == 0)
	{
		return;
	}
	int status = autoHp.GetCheck();
	DWORD realWrite = 0;
	if (status) 
	{
		hpFlag = 1;
		hpAllocAddr = (char*)VirtualAllocEx(hProcess, 0, 0x100, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		autoHpFlag = (int*)VirtualAllocEx(hProcess, 0, 0x4, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		
		WriteProcessMemory(hProcess, hpAllocAddr, autoHpFunc, 0x100, &realWrite);
		WriteProcessMemory(hProcess, autoHpFlag, &hpFlag, 0x4, &realWrite);
		remoteThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)hpAllocAddr, autoHpFlag, 0, 0);
	}
	else
	{
		hpFlag = 0;
		if (remoteThread == 0)
		{
			return;
		}
		WriteProcessMemory(hProcess, autoHpFlag, &hpFlag, 0x4, &realWrite);
		WaitForSingleObjectEx(remoteThread, INFINITE, TRUE);
		VirtualFreeEx(hProcess, hpAllocAddr, 0, MEM_RELEASE);
		VirtualFreeEx(hProcess, autoHpFlag, 0, MEM_RELEASE);
	}
	
}


//实现自动施法
void MySwordPlug::AutoCast()
{
	// TODO: 在此添加控件通知处理程序代码
}
