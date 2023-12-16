#pragma once
#include "afxdialogex.h"


// CMyDlg12 对话框

class CMyDlg12 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg12)

public:
	CMyDlg12(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDlg12();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl listCtl;
	virtual BOOL OnInitDialog();
	CImageList imageList;
	afx_msg void OnNMRClickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenu1Click();
};
