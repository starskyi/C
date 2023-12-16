#include <stdio.h>

int main(void)
{
	
	int i, j;
	char ch;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%c", '$');
		printf("\n");
	}

	for (i = 0; i < 6; i++)
	{
		for (ch = 'F', j = 0; j <= i; j++, ch--)
			printf("%c", ch);
		printf("\n");
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0,ch = 'A'; j <= i; j++, ch++)
			printf("%c", ch);

		for (j = 0, ch = 'A' + i; j < i; j++)
		{
			ch--;
			printf("%c", ch);
		}
		printf("\n");
	}

	return 0;
}