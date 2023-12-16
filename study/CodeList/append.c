#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define BUFSIZE 4096
char* s_gets(char* ch, int n);
void append(FILE* src, FILE* des);
int main(void)
{
	char src_name[SIZE];
	char des_name[SIZE];
	int files = 0;

	FILE* src, * des;
	puts("Please input the destination file name:");
	s_gets(des_name, SIZE);
	if (src_name[0] == '\0')
		return;

	if ((des = fopen(des_name, "a+")) == NULL)
	{
		fprintf(stderr, "Cannot open file:%s\n", des_name);
		exit(EXIT_FAILURE);
	}
	if (setvbuf(des, NULL, _IOFBF, BUFSIZE) != 0)
	{
		fprintf(stderr, "Cannot set buffer for file %s\n", des_name);
		exit(EXIT_FAILURE);
	}

	puts("Please input the source file name:");

	while (s_gets(src_name, SIZE) && src_name[0] != '\0')
	{
		if ( (strcmp(src_name, des_name)) == 0)
		{
			fprintf(stderr, "Cannot append file to itself\n");
			puts("Please input the source file name:");
			continue;
		}

		if ((src = fopen(src_name, "r")) == NULL)
		{
			fprintf(ferror, "Cannot open file:%s\n", src_name);
			continue;
		}
		if (setvbuf(src, NULL, _IOFBF, BUFSIZE) != 0)
		{
			fprintf(ferror, "Cannot set buffer for %s\n", src_name);
			exit(EXIT_FAILURE);
		}

		append(src, des);
		files++;
		fclose(src);
		puts("Please input next file name:");

	}
	puts("Done!");
	rewind(des);
	char ch;
	while ((ch = getc(des)) != EOF)
	{
		putchar(ch);
	}
	fclose(des);

	return 0;
}

void append(FILE* src, FILE* des)
{
	size_t word;
	static char buf[BUFSIZE];
	while ((word = fread(buf, sizeof(char), BUFSIZE, src)) > 0)
	{
		fwrite(buf, sizeof(char), word, des);
	}
}
char* s_gets(char* chs, int n)
{
	char* p;
	int i = 0;
	char ch;
	if ((p = fgets(chs, n, stdin)))
	{
		while ((ch = chs[i]) != '\n' && chs[i] != '\0' && i < n )
		{
			i++;
			continue;
		}
		if (ch == '\n')
		{
			chs[i] = '\0';
		}
		if (ch == '\0')
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return p;
}

