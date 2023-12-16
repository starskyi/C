#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define NAME " TOM"
#define SIZE 40

char* s_gets(char*, int);
int main(void)
{
	
	puts("Please input message:");
	char st[SIZE];
	while (s_gets(st, SIZE))
	{
		strcat(st, NAME);
		puts(st);
		puts(NAME);
		puts("Please input message:");
	}

	return 0;
}
char* s_gets(char* st, int n)
{
	char* st1;
	st1 = fgets(st, n, stdin);
	if (st1)
	{
		int i = 0;
		while (st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}
		if (st[i] == '\n')
		{
			st[i] = '\0';
		}
		else
		{
			while (getchar() != '\n')
				continue;

		}
	}
	return st1;
}