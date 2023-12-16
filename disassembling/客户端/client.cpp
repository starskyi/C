#define _CRT_SECURE_NO_WARNINGS 1
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	SOCKET client = (SOCKET)lpParameter;

	//接收消息
	CHAR buff[0x100]{ 0 };
	while (recv(client, buff, 0x100, 0) > 0)
	{
		printf("%s\n", buff);
		
	}
	
	return 0;
}

int main(void)
{
	//1.初始化网络环境,指定Socket版本为 2.2
	WSADATA data{ 0 };
	WSAStartup(0X0202, &data);

	//2.创建Socket
	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//3.指定服务器端口IP地址
	sockaddr_in serverAddr{ 0 };
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = (USHORT)8888;
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	int result = connect(client, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

	if (result != 0)
	{
		printf("服务器连接失败，请检查网络！\n");
		return 0;
	}

	char buff[0x100];
	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, (LPVOID)client, 0, NULL);
	printf("开始会话...\n");
	while (1)
	{
		scanf("%s", buff);
		send(client, buff, 12, 0);
	}

	return 0;
}