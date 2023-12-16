#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define PRAISE "You are very Good!"


int main(void)
{
	printf("hello\n");
	char name[40];
	printf("What's your name:");
	scanf("%s", name);
	printf("Hello %s\n", name);
	printf("Your name of %zd letters occupies %zd memory cells\n", strlen(name), sizeof(name));
	printf("%s", PRAISE);

	return 0;
}