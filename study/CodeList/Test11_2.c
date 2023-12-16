#include <stdio.h>
#include <ctype.h>

#define SIZE 20

char * getchs_arr(char* ch, int n);
int main(void)
{
	char chs[SIZE];
	puts("Please input chars:");
	getchs_arr(chs, SIZE);
	int i = 0;
	while (chs[i] != '\0')
	{
		printf("%c ", chs[i++]);
	}
	return 0;
}
char * getchs_arr(char* chs, int n)
{
	char ch;
	int i = 0;
	while (!isspace((ch = getchar())) && i < n)
	{
		*(chs + i++) = ch;
	}
	chs[i] = '\0';
	return chs;
}

