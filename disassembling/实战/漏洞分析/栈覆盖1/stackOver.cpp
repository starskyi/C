#define _CRT_SECURE_NO_WARNINGS 1
#include <Windows.h>
#include <stdio.h>

int checkPassword(const char* password, int size)
{
	
	int result = strcmp(password, "666");
	char buff[4]{ 0 };
	memcpy(buff, password, size);
	return result;
}

int main(void)
{
	char password[0X300]{ 0 };
	int flag = 0;
	FILE *fp = fopen("password1.txt", "rb");
	if (fp == NULL)
	{
		return 0;
	}
	
	fread(password, sizeof(password), 1, fp);
	flag = checkPassword(password, sizeof(password));
	if (flag == 0)
	{
		MessageBoxA(0, "Success!", 0, 0);
	}
	else {
		MessageBoxA(0, "field!", 0, 0);
	}
	return 0;
}