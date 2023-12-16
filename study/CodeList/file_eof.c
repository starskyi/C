#include <stdio.h>


int main(void)
{
	int ch;

	printf("Please input text:");
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	return 0;
}