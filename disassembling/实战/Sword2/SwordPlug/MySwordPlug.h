#pragma once
#include "afxdialogex.h"
#include "resource.h"


// MySwordPlug 对话框

class MySwordPlug : public CDialogEx
{
	DECLARE_DYNAMIC(MySwordPlug)

public:
	MySwordPlug(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MySwordPlug();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	HANDLE hProcess = 0;
	char* allocAddr = NULL;
	char* hpAllocAddr = NULL;
	//窗口名称
	char winName[100] = "Sword2 Window";
	DWORD pid = 0;
	DWORD baseAddr = 0;
	//HOOK地址
	DWORD attackAddr = 0X41FD40;
	//HOOK代码
	unsigned char hookCode[8] = { 0xE9, 0X00, 0X00, 0X00, 0X00, 0x90, 0X90, 0X90 };
	//原代码
	unsigned char oldCode[8] = { 0X56, 0X8B, 0XF1, 0X57, 0X83, 0X7E, 0X04, 0X02 };
	//无敌代码
	unsigned char allocFunc[26] = { 0X56, 0X8B, 0XF1, 0X57, 0X81, 0X7E, 0X04, 0X02, 0X00,
			0X00, 0X00, 0X75, 0X08, 0XC7, 0X44, 0X24, 0X0C, 0X00, 0X00, 0X00, 0X00,
			0XE9, 0X00, 0X00, 0X00, 0X00 };
	int* autoHpFlag = NULL;
	int hpFlag = 1;
	HICON icon;
	CButton invincibleBox;
	afx_msg void Invincible();
	virtual BOOL OnInitDialog();
	CButton autoHp;
	afx_msg void AutoHP();
	CButton autoCast;
	afx_msg void AutoCast();
};
