#pragma once
#include "afxdialogex.h"


// CSubDlg3 对话框

class CSubDlg3 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg3)

public:
	CSubDlg3(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSubDlg3();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
