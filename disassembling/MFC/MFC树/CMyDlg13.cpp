// CMyDlg13.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "CMyDlg13.h"
#include "resource.h"


// CMyDlg13 对话框

IMPLEMENT_DYNAMIC(CMyDlg13, CDialogEx)

CMyDlg13::CMyDlg13(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG13, pParent)
{

}

CMyDlg13::~CMyDlg13()
{
}

void CMyDlg13::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, myTree);
}


BEGIN_MESSAGE_MAP(CMyDlg13, CDialogEx)
END_MESSAGE_MAP()


// CMyDlg13 消息处理程序


BOOL CMyDlg13::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//添加图标集合
	imageList.Create(12, 12, ILC_COLOR32, 2, 0);
	imageList.Add(LoadIcon(NULL, IDI_APPLICATION));
	imageList.Add(LoadIcon(NULL, IDI_ERROR));
	myTree.SetImageList(&imageList, TVSIL_NORMAL);

	//添加节点，并指定节点图标
	HTREEITEM beiji = myTree.InsertItem(L"北京", 0, 1);
	HTREEITEM shanghai = myTree.InsertItem(L"上海", 1, 0);
	HTREEITEM guangdong = myTree.InsertItem(L"广东");

	//添加子节点
	myTree.InsertItem(L"大兴区", beiji);
	myTree.InsertItem(L"松江", shanghai);
	myTree.InsertItem(L"广州", guangdong);

	//添加工具栏
	toolBar.Create(this);
	toolBar.LoadToolBar(IDR_TOOLBAR1);
	UINT toolBarArr[] = {40004, 40005, 40006};
	toolBar.SetButtons(toolBarArr, 3);

	//复位
	//RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);

	//设置状态栏
	statusBar.Create(this);
	UINT statusArr[] = { 0x1001, 0x1002, 0x1003 };
	statusBar.SetIndicators(statusArr, 3);
	statusBar.SetPaneInfo(0, 0x1001, SBPS_STRETCH, 100);
	statusBar.SetPaneInfo(1, 0x1002, SBPS_STRETCH, 100);
	statusBar.SetPaneInfo(2, 0x1003, SBPS_STRETCH, 100);

	statusBar.SetPaneText(0, L"程序");
	statusBar.SetPaneText(1, L"CPU");
	statusBar.SetPaneText(2, L"时间");

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST, AFX_IDW_CONTROLBAR_LAST, 0);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
