#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int days,cur_num = 5;

	printf("Please enter the number of weeks:");

	while (scanf("%d", &days))
	{
		for (int i = 0; i < days; i++)
		{
			cur_num--;
			cur_num *= 2;
		}
		printf("Now you hava %d friends in all\n", cur_num);
		printf("Please enter the number:");
	}
}