#include <afxwin.h>
#include "resource.h"
#include "CMainDialog.h"

class CMyWnd : public CWinApp
{
	virtual BOOL InitInstance() override
	{
		CMainDialog* myDialog = new CMainDialog();
		myDialog->DoModal();
		return TRUE;
	}
};

CMyWnd myWnd;