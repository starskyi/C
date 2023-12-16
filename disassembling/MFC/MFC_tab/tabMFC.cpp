#include <afxwin.h>
#include "CMyDlg8.h"

class TabMFC : public CWinApp
{
	BOOL InitInstance() override
	{
		CWinApp::InitInstance();
		CMyDlg8 myDlg8;
		m_pMainWnd = &myDlg8;
		myDlg8.DoModal();
		return TRUE;
	}
};

TabMFC tabMFC;