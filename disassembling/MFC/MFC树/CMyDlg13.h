#pragma once
#include "afxdialogex.h"
#include "afxext.h"

// CMyDlg13 对话框

class CMyDlg13 : public CDialogEx
{
	DECLARE_DYNAMIC(CMyDlg13)

public:
	CMyDlg13(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMyDlg13();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl myTree;
	virtual BOOL OnInitDialog();
	CImageList imageList;
	CToolBar toolBar;
	CStatusBar statusBar;
};
