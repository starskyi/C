#pragma once
#include "afxdialogex.h"


// CMyDlg7 对话框

class CMyDlg7 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg7)

public:
	CMyDlg7(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDlg7();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
//	afx_msg void OnStnClickedStatic4();
	CStatic pictureCtl;
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox comboBoxCtl;
	afx_msg void OnBnClickedShow();
};
