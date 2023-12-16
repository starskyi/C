// CMyButton.cpp: 实现文件
//

#include "pch.h"
#include "myapp.h"
#include "CMyButton.h"


// CMyButton

IMPLEMENT_DYNAMIC(CMyButton, CButton)

CMyButton::CMyButton()
{

}

CMyButton::~CMyButton()
{
}


BEGIN_MESSAGE_MAP(CMyButton, CButton)
	ON_WM_MOUSEHOVER()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CMyButton 消息处理程序





//实现鼠标覆盖按钮随机移动
void CMyButton::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	//1.获取父窗口区域
	CRect pRect{ 0 };
	GetParent()->GetClientRect(pRect);

	//2.获取按钮区域
	CRect btRect{ 0 };
	GetClientRect(btRect);

	//3.获取随机坐标
	int x = rand() % (pRect.Width() - btRect.Width());
	int y = rand() % (pRect.Height() - btRect.Height());

	//4.设置新位置
	btRect.MoveToXY(x, y);
	MoveWindow(btRect);

	CButton::OnMouseMove(nFlags, point);
}
