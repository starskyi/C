// CMainDialog.cpp: 实现文件
//

//#include "pch.h"
#include "afxdialogex.h"
#include "CMainDialog.h"


// CMainDialog 对话框

IMPLEMENT_DYNAMIC(CMainDialog, CDialogEx)

CMainDialog::CMainDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, myEdit1(_T(""))
{

}

CMainDialog::~CMainDialog()
{
}

void CMainDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, myEdit1);
}


BEGIN_MESSAGE_MAP(CMainDialog, CDialogEx)
	ON_WM_LBUTTONDBLCLK()
	ON_BN_CLICKED(IDOK, &CMainDialog::OnBnClickedOk)
END_MESSAGE_MAP()


// CMainDialog 消息处理程序


void CMainDialog::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	CString text;
	text.Format(L"x=%lu, y=%lu\n", point.x, point.y);
	MessageBoxW(text);
	//::MessageBoxW(this->m_hWnd, text, L"消息", MB_OK);


	CDialogEx::OnLButtonDblClk(nFlags, point);
}


void CMainDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	MessageBoxW(myEdit1);
	//CDialogEx::OnOK();
}
