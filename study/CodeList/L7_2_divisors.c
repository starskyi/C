#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
	unsigned long num,div;
	bool flag;

	printf("Please enter an integer for analysis:");
	while (scanf("%lu", &num))
	{
		for (div = 1, flag = true; div * div <= num; div++)
		{
			if ((num % div) == 0)
			{
				
				flag = false;
				if (div * div == num) {
					printf("%lu is divisible by %lu\n", num, div);
				}
				else
					printf("%lu is divisible by %lu and %lu\n", num, div, num / div);
			}
		}
		if (flag)
		{
			printf("%lu is prime\n", num);
		}
		printf("Please enter an integer for analysis:");
	}
}