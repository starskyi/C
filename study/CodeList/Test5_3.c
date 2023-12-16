#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int num;
	int max_num;

	printf("Please enter a number for print:");
	scanf("%d", &num);
	max_num = num + 10;

	while (num <= max_num)
	{
		printf("%d\n", num);
		num++;

	}


	return 0;
}