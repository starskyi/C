#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 40

bool get_chs(char* chs, int n);
int main(void)
{
	char chs[MAX] = {0};
	puts("Please input string:");
	while (get_chs(chs, MAX))
	{
		for (int i = strlen(chs) - 1; i >= 0; i--)
		{
			printf("%c", chs[i]);
		}
		printf("\n");
		puts("Please input string:");
	}
	return 0;
}

bool get_chs(char* chs, int n)
{
	int i = 0;
	char ch;
	char prev = '\n';
	while (isspace((ch = getchar())))
	{
		if (prev == '\n' && ch == '\n')
			return false;
		continue;
	}
	*chs = ch;
	i++;
	while (i < n - 1 && (ch = getchar()) != '\n')
	{
		*(chs + i) = ch;
		i++;
	}
	*(chs + i) = '\0';
	return true;
}