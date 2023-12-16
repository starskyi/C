// CMyDlg7.cpp: 实现文件
//

//#include "pch.h"
#include "afxdialogex.h"
#include "CMyDlg7.h"
#include "resource.h"
#include <atlimage.h>


// CMyDlg7 对话框

IMPLEMENT_DYNAMIC(CMyDlg7, CDialogEx)

CMyDlg7::CMyDlg7(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

CMyDlg7::~CMyDlg7()
{
}

void CMyDlg7::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, pictureCtl);
	DDX_Control(pDX, IDC_COMBO1, comboBoxCtl);
}


BEGIN_MESSAGE_MAP(CMyDlg7, CDialogEx)
ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg7::OnBnClickedShow)
END_MESSAGE_MAP()


// CMyDlg7 消息处理程序





BOOL CMyDlg7::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	SetTimer(0x11, 2000, nullptr);

	//初始化下拉框
	comboBoxCtl.AddString(L"北京");
	comboBoxCtl.AddString(L"上海");
	comboBoxCtl.AddString(L"广东");
	comboBoxCtl.SetCurSel(0);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


//时钟事件
void CMyDlg7::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	static int index = 0;
	if (index < 4) {
		index++;
	}
	else {
		index = 0;
	}
	HBITMAP bitmap = LoadBitmapW(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1 + index));
	pictureCtl.SetBitmap(bitmap);
	CDialogEx::OnTimer(nIDEvent);
}


//获取下拉框内容
void CMyDlg7::OnBnClickedShow()
{
	// TODO: 在此添加控件通知处理程序代码
	CString curtext;
	comboBoxCtl.GetWindowTextW(curtext);
	MessageBoxW(curtext);
}
