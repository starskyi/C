// CMyDlg8.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "CMyDlg8.h"
#include "resource.h"
#include "CSubDlg1.h"
#include "CSubDlg2.h"
#include "CSubDlg3.h"


// CMyDlg8 对话框

IMPLEMENT_DYNAMIC(CMyDlg8, CDialogEx)

CMyDlg8::CMyDlg8(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

CMyDlg8::~CMyDlg8()
{
}

void CMyDlg8::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, tabCtl);
}


BEGIN_MESSAGE_MAP(CMyDlg8, CDialogEx)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CMyDlg8::OnTcnSelchangeTab1)
END_MESSAGE_MAP()


// CMyDlg8 消息处理程序


BOOL CMyDlg8::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	tabCtl.InsertItem(0, L"选项1");
	tabCtl.InsertItem(1, L"选项2");
	tabCtl.InsertItem(2, L"选项3");

	dlgs[0] = new CSubDlg1();
	dlgs[1] = new CSubDlg2();
	dlgs[2] = new CSubDlg3();

	CRect rect{};
	tabCtl.GetClientRect(rect);
	rect.DeflateRect(10, 30, 10, 10);


	dlgs[0]->Create(IDD_DIALOG9, &tabCtl);
	dlgs[1]->Create(IDD_DIALOG10, &tabCtl);
	dlgs[2]->Create(IDD_DIALOG11, &tabCtl);
	dlgs[0]->ShowWindow(SW_SHOWNORMAL);

	
	for (int i = 0; i < 3; i++) {
		dlgs[i]->MoveWindow(rect);
	}
	dlgs[0]->MoveWindow(rect);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CMyDlg8::OnTcnSelchangeTab1(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int index = tabCtl.GetCurSel();
	for (int i = 0; i < 3; i++) {
		dlgs[i]->ShowWindow(SW_HIDE);
	}
	dlgs[index]->ShowWindow(SW_SHOWNORMAL);
}
