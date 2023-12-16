#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main(void)
{
	char fname[30], lname[30];

	printf("Please input your last name:");
	scanf("%s", lname);
	printf("Please input your first name:");
	scanf("%s", fname);

	printf("%-6s %-6s\n", fname, lname);
	printf("%-6d %-6d\n", strlen(fname), strlen(lname));

	return 0;
}