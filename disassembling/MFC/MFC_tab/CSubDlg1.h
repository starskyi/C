#pragma once
#include "afxdialogex.h"


// CSubDlg1 对话框

class CSubDlg1 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg1)

public:
	CSubDlg1(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSubDlg1();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
