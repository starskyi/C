#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40

int main(int argc, char *argv[])
{
	char ch;
	int count = 0;
	if (argc != 2)
	{
		printf("Usage:program filename");
		exit(EXIT_FAILURE);
	}
	FILE* fp;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		printf("Cannot open file:%s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	printf("\n");
	while ((ch = getc(fp)) != EOF)
	{
		putc(ch, stdout);
		count++;
	}
	printf("\n");
	printf("total count is %d \n", count);
	fclose(fp);
	return 0;
}