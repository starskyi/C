#define _CRT_SECURE_NO_WARNINGS 1
#include <WinSock2.h>
#include <Windows.h>
#include <iostream>
#include <WS2tcpip.h>

#pragma comment(lib, "ws2_32.lib")

DWORD WINAPI ThreadProc(LPVOID lpParameter)
{
	SOCKET client = (SOCKET)lpParameter;

	//������Ϣ
	CHAR buff[0x100]{ 0 };
	while (recv(client, buff, 0x100, 0) > 0)
	{
		printf("%s\n", buff);
		
	}
	
	return 0;
}

int main(void)
{
	//1.��ʼ�����绷��,ָ��Socket�汾Ϊ 2.2
	WSADATA data{ 0 };
	WSAStartup(0X0202, &data);

	//2.����Socket
	SOCKET client = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//3.ָ���������˿�IP��ַ
	sockaddr_in serverAddr{ 0 };
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = (USHORT)8888;
	inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr);
	int result = connect(client, (SOCKADDR*)&serverAddr, sizeof(serverAddr));

	if (result != 0)
	{
		printf("����������ʧ�ܣ��������磡\n");
		return 0;
	}

	char buff[0x100];
	HANDLE hThread = CreateThread(NULL, NULL, ThreadProc, (LPVOID)client, 0, NULL);
	printf("��ʼ�Ự...\n");
	while (1)
	{
		scanf("%s", buff);
		send(client, buff, 12, 0);
	}

	return 0;
}