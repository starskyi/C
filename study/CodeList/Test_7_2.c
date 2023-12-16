#include <stdio.h>

int main(void)
{
	char ch;
	char chs[50];
	int count = 0;
	int i = 0;

	printf("Please input text:");
	while ((chs[count] = getchar()) != '#')
	{
		count++;
	}
	count--;

	while (i < count)
	{
		printf("%d ", chs[i]);
		if ((i + 1) % 8 == 0)
		{
			printf("\n");
		}
		i++;
	}
	return 0;
}