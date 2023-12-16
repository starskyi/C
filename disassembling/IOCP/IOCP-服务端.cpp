#define _CRT_SECURE_NO_WARNINGS 1
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <WS2tcpip.h>
#include <list>
#include <String.h>

#pragma comment(lib, "ws2_32.lib")

using std::list;
using std::string;

typedef struct
{
	OVERLAPPED overLapped;
	WSABUF wsaBuf;
}MY_OVERLAPPED, *LPMY_OVERLAPPED;

list<SOCKET> clients;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	LPMY_OVERLAPPED lpOverLapped = new MY_OVERLAPPED{ 0 };
	
	DWORD realRead = 0;
	DWORD flag = 0;

	DWORD numberOfBytesTransferred;
	ULONG_PTR   client;
	BOOL result = FALSE;
	CHAR context[0x200];
	while (1)
	{
		result = GetQueuedCompletionStatus((HANDLE)lpParameter, &numberOfBytesTransferred, &client, (LPOVERLAPPED*)&lpOverLapped, INFINITE);
		
		if (result && numberOfBytesTransferred > 0) 
		{
			printf("客服端%u发来消息:%s\n", client, lpOverLapped->wsaBuf.buf);
			list<SOCKET>::iterator p;
			for (p = clients.begin(); p != clients.end(); p++)
			{

				//strcpy_s(cliBuff, 0x11, buff);
				if (*p != client)
				{
					sprintf(context, "客户%u:%s", client, lpOverLapped->wsaBuf.buf);
					send(*p, context, 0x100, 0);
				}

			}
		}
		else {
			printf("客户%u下线了!\n", client);
			closesocket(client);
			clients.remove(client);
		}
		WSARecv(client, &lpOverLapped->wsaBuf, 1, &realRead, &flag, (LPWSAOVERLAPPED)lpOverLapped, NULL);
	}

	
	return 0;
}

int main(void)
{
	//创建IOCP对象
	HANDLE hIOCP = CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, 0);
	
	//获取CUP内核数量
	SYSTEM_INFO systemInfo{ 0 };
	GetNativeSystemInfo(&systemInfo);
	for (int i = 0; i < systemInfo.dwNumberOfProcessors * 2; i++)
	{
		CreateThread(NULL, NULL, ThreadProc, (LPVOID)hIOCP, 0, NULL);
	}

	
	//1.初始化网络环境,指定Socket版本为 2.2
	WSADATA data{ 0 };
	WSAStartup(0X0202, &data);

	//2.创建Socket
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//3.绑定端口IP地址
	sockaddr_in serverAddr{ 0 };
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = (USHORT)8888;
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	bind(server, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

	//4.监听
	listen(server, SOMAXCONN);

	//5.接收会话
	sockaddr_in clientAddr{ 0 };
	int size = sizeof(clientAddr);
	SOCKET client;

	printf("============服务器启动==========\n");
	printf("等待客户连接...\n");
	while (1)
	{
		client = accept(server, (SOCKADDR*)&clientAddr, &size);
		clients.push_back(client);

		//将SOCKET关联到IOCP
		CreateIoCompletionPort((HANDLE)client, hIOCP, client, 0);

		LPMY_OVERLAPPED lpOverLapped = new MY_OVERLAPPED{ 0 };
		lpOverLapped->wsaBuf.len = 0x100;
		lpOverLapped->wsaBuf.buf = new CHAR[0x100];
		DWORD realRead = 0;
		DWORD flag = 0;

		WSARecv(client, &lpOverLapped->wsaBuf, 1, &realRead, &flag, (LPWSAOVERLAPPED)lpOverLapped, NULL);

		printf("客户%u上线了!\n", client);
		
	}



	return 0;
}