#pragma once
#include "afxdialogex.h"
#include "resource.h"

// CMyDlg6 对话框

class CMyDlg6 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg6)

public:
	CMyDlg6(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDlg6();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	int myRadio1;
	afx_msg void OnClickedGetRadio();
	BOOL myCheck1;
	BOOL myCheck2;
	BOOL myCheck3;
	BOOL myCheckAll;
	afx_msg void OnClickedGetCheck();
	afx_msg void OnClickedCheckAll();
	afx_msg void OnCommandRange(UINT id);

	CEdit usrname;
	CEdit passwd;
	afx_msg void OnClickedLogin();
	virtual BOOL OnInitDialog();
	CProgressCtrl processCtl;
	CSliderCtrl sliderCtl;
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);


	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
