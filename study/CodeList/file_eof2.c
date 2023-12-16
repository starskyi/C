#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char filename[40];
	int ch;

	printf("Please input filename:");
	scanf("%s", filename);

	FILE* fp;
	
	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		printf("Failed to open file %s\n", filename);
			exit(1);
	}

	while ((ch = getc(fp)) != EOF)
	{
		putchar(ch);
	}
	fclose(fp);

	return 0;
}