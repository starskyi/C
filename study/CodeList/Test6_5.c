#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int min_number, max_number,i;

	printf("Please enter a minimum number and maximun number:");

	while (scanf("%d %d", &min_number, &max_number))
	{
		printf("cur_number  number_square  number_cube\n\n");
		for (i = min_number; i <= max_number; i++)
		{
			printf("%-12d %-12d %-12d\n\n", i, i * i, i * i * i);
		}
		printf("Please enter a minimum number and maximun number:");
	}
	
}