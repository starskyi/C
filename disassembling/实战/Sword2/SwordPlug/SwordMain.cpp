#include <afxwin.h>
#include "MySwordPlug.h"

class CmyWnd : public CWinApp
{
	virtual BOOL InitInstance() override
	{
		MySwordPlug* mySword = new MySwordPlug();
		m_pMainWnd = mySword;
		mySword->DoModal();
		return TRUE;
	}
};

CmyWnd myWnd;
