#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
int main(void)
{
	int num, i, j;
	bool flag;

	printf("Please enter a number:");
	while (scanf("%d", &num))
	{
		for (i = 2; i <= num; i++)
		{
			flag = true;
			for (j = 2; j * j <= i; j++)
			{
				if (i % j == 0)
				{
					flag = false;
				}
			}
			if (flag)
			{
				printf("%d ", i);
			}
		}
		printf("\nPlease enter a number:");

	}
}