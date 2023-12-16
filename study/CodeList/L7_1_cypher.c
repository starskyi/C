#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	char ch;

	while ((ch = getchar()) != '\n')
	{
		if (ch == ' ')
		{
			putchar(ch);
		}
		else
		{
			putchar(ch + 1); 
		}
	}
}