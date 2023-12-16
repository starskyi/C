#include <afxwin.h>
#include "CMyDlg13.h"

class ListMFC : CWinApp
{
	BOOL InitInstance() override
	{
		CWinApp::InitInstance();
		CMyDlg13 dlg13;
		m_pMainWnd = &dlg13;
		dlg13.DoModal();
		return TRUE;
	}

};

ListMFC listMFC;