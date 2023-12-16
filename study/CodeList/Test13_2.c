#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 256

int has_ch(char ch, char* line);
int main(int argc, char* argv[])
{
	FILE* fp;
	
	if (argc != 3)
	{
		printf("Usage:%s character filename", *argv);
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[2], "r")) == NULL)
	{
		printf("Cannot open file:%s\n", argv[2]);
		exit(EXIT_FAILURE);
	}
	
	
	char chs[SIZE];
	while (fgets(chs, SIZE, fp) != NULL)
	{
		if (has_ch(argv[1][0], chs))
		{
			fputs(chs, stdout);
		}
	}

	fclose(fp);
	return 0;
}

int has_ch(char ch, char* chs)
{
	while (*chs != '\0')
	{
		if (ch == *chs++)
		{
			return 1;
		}
	}
	return 0;
}