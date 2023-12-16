#include <stdio.h>
#define SIZE 20

char* save_char(int n);
int main(void)
{
	puts("Please input string:");
	
	
	char* p;
	p = save_char(SIZE);
	
	while (*p != '\0')
	{
		printf("%c %d   ", *p, *p);
		p++;
	}
	return 0;
}

char* save_char(int n)
{
	char st[SIZE];

	char ch;
	int i = 0;
	while ((ch = getchar()) != EOF && i < n)
	{
		*(st + i) = ch;
		i++;
	}
	st[i - 1] = '\0';
	
	return st;
}
