#include <afxwin.h>
#include "CMyDlg7.h"

class MyMFC4 : public CWinApp
{
	BOOL InitInstance() override
	{
		CWinApp::InitInstance();
		CMyDlg7 myDlg7;
		m_pMainWnd = &myDlg7;
		myDlg7.DoModal();
		return TRUE;
	}
};

MyMFC4 myMFC4;