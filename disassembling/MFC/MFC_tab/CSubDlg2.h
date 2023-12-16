#pragma once
#include "afxdialogex.h"


// CSubDlg2 对话框

class CSubDlg2 : public CDialogEx
{
	DECLARE_DYNAMIC(CSubDlg2)

public:
	CSubDlg2(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CSubDlg2();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
