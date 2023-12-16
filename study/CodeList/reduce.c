#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
int main(int argc, char *argv[])
{
	char name[SIZE];
	char ch;
	int count = 0;
	if (argc != 2)
	{
		puts("Usage:program filename");
		exit(EXIT_FAILURE);
	}
	FILE *fpr, *fpw;
	if ((fpr = fopen(argv[1], "r")) == NULL)
	{
		printf("Cannot open file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	strncpy(name, argv[1], SIZE - 5);
	name[SIZE - 5] = '\0';
	printf("%s\n", name);
	strcat(name, ".red");
	if ((fpw = fopen(name, "w")) == NULL)
	{
		printf("Cannot open file:%s\n", name);
		exit(EXIT_FAILURE);
	}
	while ((ch = getc(fpr)) != EOF)
	{
		if (count % 3 == 0)
		{
			putc(ch, fpw);
		}
		count++;
	}
	if (fclose(fpr) != 0 || fclose(fpw) != 0)
		fprintf(stdout, "error in closing files");
	return 0;
}