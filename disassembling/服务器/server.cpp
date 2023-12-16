#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <WS2tcpip.h>
#include <list>
#include <String.h>

#pragma comment(lib, "ws2_32.lib")

using std::list;
using std::string;

list<SOCKET> clients;

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	SOCKET client = (SOCKET)lpParameter;
	
	//接收消息
	CHAR buff[0x100]{ 0 };
	while (recv(client, buff, 0x100, 0) > 0)
	{
		printf("客服端%u发来消息:%s\n", client, buff);
		list<SOCKET>::iterator p;
		for (p = clients.begin(); p != clients.end(); p++) 
		{
			 
			//strcpy_s(cliBuff, 0x11, buff);
			if (*p != client)
			{
				//strcpy
				send(*p, buff, 0x100, 0);
			}
			
		}
	}
	printf("客户%u下线了!\n", client);
	closesocket(client);
	clients.remove(client);
	return 0;
}

int main(void)
{
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

	while (1)
	{
		client = accept(server, (SOCKADDR*)&clientAddr, &size);
		clients.push_back(client);
		printf("客户%u上线了!\n", client);
		CreateThread(NULL, NULL, ThreadProc, (LPVOID)client, 0, NULL);
	}
	
	

	return 0;
}