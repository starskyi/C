#include <afxwin.h>
#include "CMyDlg13.h"

class ListMFC : public CWinApp
{
	BOOL InitInstance() override
	{
		CWinApp::InitInstance();
		CMyDlg13 myDlg13;
		m_pMainWnd = &myDlg13;
		myDlg13.DoModal();
		return TRUE;
	}
};

ListMFC listMFC;