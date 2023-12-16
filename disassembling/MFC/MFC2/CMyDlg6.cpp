// CMyDlg6.cpp: 实现文件
//

//#include "pch.h"
#include "afxdialogex.h"
#include "CMyDlg6.h"
#include "resource.h"


void print(LPCWSTR format, ...)
{
	WCHAR buff[100]{ 0 };
	va_list ap;
	va_start(ap, format);
	wvsprintfW(buff, format, ap);
	va_end(ap);
	OutputDebugStringW(buff);

}
// CMyDlg6 对话框

IMPLEMENT_DYNAMIC(CMyDlg6, CDialogEx)

CMyDlg6::CMyDlg6(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, myRadio1(FALSE)
	, myCheck1(FALSE)
	, myCheck2(FALSE)
	, myCheck3(FALSE)
	, myCheckAll(FALSE)
{
	
}

CMyDlg6::~CMyDlg6()
{
}

void CMyDlg6::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Radio(pDX, IDC_RADIO1, myRadio1);
	DDX_Check(pDX, IDC_CHECK2, myCheck1);
	DDX_Check(pDX, IDC_CHECK1, myCheck2);
	DDX_Check(pDX, IDC_CHECK3, myCheck3);
	DDX_Check(pDX, IDC_CHECK4, myCheckAll);
	DDX_Control(pDX, IDC_EDIT1, usrname);
	DDX_Control(pDX, IDC_EDIT2, passwd);
	DDX_Control(pDX, IDC_PROGRESS1, processCtl);
	DDX_Control(pDX, IDC_SLIDER1, sliderCtl);
}


BEGIN_MESSAGE_MAP(CMyDlg6, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyDlg6::OnClickedGetRadio)
	ON_BN_CLICKED(IDC_BUTTON3, &CMyDlg6::OnClickedGetCheck)
	ON_BN_CLICKED(IDC_CHECK4, &CMyDlg6::OnClickedCheckAll)
	ON_COMMAND_RANGE(IDC_CHECK1, IDC_CHECK3, OnCommandRange)
	ON_BN_CLICKED(IDC_BUTTON2, &CMyDlg6::OnClickedLogin)
	ON_WM_HSCROLL()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CMyDlg6 消息处理程序


void CMyDlg6::OnClickedGetRadio()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strBuff;
	UpdateData();
	GetDlgItemTextW(IDC_RADIO1 + myRadio1, strBuff);
	MessageBox(strBuff);
	print(L"%d", myRadio1);
	
}


void CMyDlg6::OnClickedGetCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	CString resultBuff, tmpBuff;
	/*for (int currCheck = IDC_CHECK1; currCheck <= IDC_CHECK1 + 2; currCheck++) {
		if(currCheck)
	}*/
	UpdateData();
	if (myCheck1 == 1) {
		GetDlgItemTextW(IDC_CHECK2,tmpBuff);
		resultBuff = resultBuff + tmpBuff + ",";
	}
	if (myCheck2 == 1) {
		GetDlgItemTextW(IDC_CHECK1, tmpBuff);
		resultBuff = resultBuff + tmpBuff + ",";
	}
	if (myCheck3 == 1) {
		GetDlgItemTextW(IDC_CHECK3, tmpBuff);
		resultBuff = resultBuff + tmpBuff + ",";
	}
	MessageBox(resultBuff);
}


void CMyDlg6::OnClickedCheckAll()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData();
	myCheck1 = myCheckAll;
	myCheck2 = myCheckAll;
	myCheck3 = myCheckAll;
	UpdateData(FALSE);

}

void CMyDlg6::OnCommandRange(UINT id) {
	int all = 0;
	UpdateData();
	all += myCheck1;
	all += myCheck2;
	all += myCheck3;

	if (all == 3) {
		myCheckAll = 1;
	}
	else {
		myCheckAll = 0;
	}
	UpdateData(FALSE);
}


void CMyDlg6::OnClickedLogin()
{
	CString username;
	CString password;
	// TODO: 在此添加控件通知处理程序代码


	usrname.GetWindowTextW(username);
	passwd.GetWindowTextW(password);
	if (username.IsEmpty()) {
		MessageBoxW(L"用户名不能为空");
	}
	if (password.IsEmpty()) {
		MessageBoxW(L"密码不能为空");
	}

}


BOOL CMyDlg6::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//限制用户名和密码长度
	usrname.SetLimitText(10);
	passwd.SetLimitText(8);
	processCtl.SetRange(0, 100);
	sliderCtl.SetRange(0, 100);
	processCtl.SetPos(100);
	processCtl.SetStep(10);
	SetTimer(0x11, 1000 ,nullptr);
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



void CMyDlg6::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//获取滑块当前值并设置给进度条
	processCtl.SetPos(sliderCtl.GetPos());

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CMyDlg6::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	processCtl.StepIt();

	CDialogEx::OnTimer(nIDEvent);
}

