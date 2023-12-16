#include <Windows.h>
#pragma comment(linker, "/INCLUDE:__tls_used")

void NTAPI TLS_CALLBACK1(PVOID dllHandle, DWORD reason, PVOID reserved)
{
	if (reason == DLL_PROCESS_ATTACH)
	{
		BOOL result = FALSE;
		HANDLE hNewHandle = 0;

		DuplicateHandle(
			GetCurrentProcess(),
			GetCurrentProcess(),
			GetCurrentProcess(),
			&hNewHandle,
			NULL,
			NULL,
			DUPLICATE_SAME_ACCESS
		);
		
		CheckRemoteDebuggerPresent(hNewHandle, &result);
		if(result)
		{
			MessageBoxA(0, "程序被掉调试了!", "警告", MB_OK);
			ExitProcess(0);
		}
	}
}
#pragma data_seg(".CRT$XLX")
PIMAGE_TLS_CALLBACK pTLS_CALLBACKs[] = { TLS_CALLBACK1, 0 };
#pragma data_seg()


int main(void)
{

	MessageBoxA(0, "hello world\n", 0, 0);
	return 0;
}