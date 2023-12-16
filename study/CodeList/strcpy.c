#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define SIZE 40
#define ROW 5

char* s_gets(char* st, int n);
int main(void)
{
	char st[SIZE];
	char sts[ROW][SIZE];
	int i = 0,j;
	puts("Please input:");
	while (s_gets(st, SIZE) && i < ROW)
	{
		if (st[0] == '\0')
		{
			break;
		}

		strcpy(sts[i++], st);
		if (i == ROW)
		{
			break;
		}

	}
	

	for (j = 0; j < i; j++)
	{
		puts(sts[j]);
	}

	return 0;
}

char* s_gets(char* st, int n)
{
	char* st1;
	if ((st1 = fgets(st, n, stdin)))
	{
		int i = 0;
		while (st[i] != '\n' && st[i] != '\0')
		{
			i++;
			continue;
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

}