#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>


void judge(int ch);
int main(void)
{
	int ch;
	int count = 0;
	char prev = '\n';

	while ((ch = getchar()) != EOF)
	{
		if (prev == '\n')
		{
			count = 0;
		}
		count++;
		prev = ch;
		judge(ch);
		if (count % 10 == 0)
			printf("\n");
		

	}
	
	return 0;
}

void judge(int ch)
{
	if (ch >= 32)
	{
		putchar(ch);
		printf(" %d   ", ch);
	}
	else
	{
		switch (ch)
		{
		case 9:
			printf("%s", "\\t");
			printf(" %d   ", ch);
			break;
		case 10:
			printf("%s", "\\n");
			printf(" %d   ", ch);
			printf("\n");
			break;
		default:
			printf("%c%c", '^', ch + 64);
			printf(" %d   ", ch);
			break;
		}
			

	}
}