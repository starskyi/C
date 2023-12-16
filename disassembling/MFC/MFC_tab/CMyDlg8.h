#pragma once
#include "afxdialogex.h"


// CMyDlg8 对话框

class CMyDlg8 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg8)

public:
	CMyDlg8(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDlg8();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CTabCtrl tabCtl;
	CDialogEx *dlgs[3]{ 0 };
	afx_msg void OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult);
};
