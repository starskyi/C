#include <stdio.h>

int main(void)
{
	int ch;
	int count = 0;

	while ((ch = getchar()) != EOF)
	{
		count++;
	}
	printf("%d\n", count);
	return 0;
}