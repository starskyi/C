// CMyDlg12.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "CMyDlg12.h"
#include "resource.h"


// CMyDlg12 对话框

IMPLEMENT_DYNAMIC(CMyDlg12, CDialogEx)

CMyDlg12::CMyDlg12(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG12, pParent)
{

}

CMyDlg12::~CMyDlg12()
{
}

void CMyDlg12::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, listCtl);
}


BEGIN_MESSAGE_MAP(CMyDlg12, CDialogEx)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, &CMyDlg12::OnNMRClickList1)
	ON_COMMAND(ID_40001, &CMyDlg12::OnMenu1Click)
END_MESSAGE_MAP()


// CMyDlg12 消息处理程序


BOOL CMyDlg12::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//初始化图标数组
	imageList.Create(12,12, ILC_COLOR32,3, 0);
	imageList.Add(LoadIcon(NULL, IDI_APPLICATION));
	imageList.Add(LoadIcon(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_JPG1)));
	imageList.Add(LoadIcon(NULL, IDI_ERROR));
	//imageList.Add(LoadIcon(NULL, IDI_ERROR));
	//设置样式
	listCtl.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	listCtl.SetImageList(&imageList, LVSIL_SMALL);
	//插入列
	listCtl.InsertColumn(0, L"程序名称", LVCFMT_LEFT, 120);
	listCtl.InsertColumn(1, L"PID", LVCFMT_LEFT, 120);
	listCtl.InsertColumn(2, L"状态", LVCFMT_LEFT, 120);

	//插入行
	listCtl.InsertItem(0, L"QQ.exe", 0);
	listCtl.InsertItem(1, L"微信.exe", 2);

	//插入项
	listCtl.SetItemText(0, 1, L"123");
	listCtl.SetItemText(0, 2, L"正在运行");
	listCtl.SetItemText(1, 1, L"124");
	listCtl.SetItemText(1, 2, L"等待运行");
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}




void CMyDlg12::OnNMRClickList1(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代

	POINT point{0};
	GetCursorPos(&point);

	CMenu menu;
	menu.LoadMenuW(IDR_MENU1);
	CMenu *psubMenu = menu.GetSubMenu(0);
	psubMenu->TrackPopupMenu(TPM_LEFTALIGN, point.x, point.y, this);
	*pResult = 0;
}


void CMyDlg12::OnMenu1Click()
{
	// TODO: 在此添加命令处理程序代码

	MessageBoxW(L"打开文件");
}
