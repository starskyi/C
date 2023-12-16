#include <afxwin.h>
#include "CMyDlg6.h"

class MyMFC3 : public CWinApp
{
	BOOL InitInstance() override
	{
		CWinApp::InitInstance();
		CMyDlg6 myDlg6;
		m_pMainWnd = &myDlg6;
		myDlg6.DoModal();
		return TRUE;
	}
};

MyMFC3 myMFC3;