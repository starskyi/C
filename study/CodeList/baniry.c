#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void to_baniry(int num);
int main(void)
{
	int num;

	printf("Please input a number to print baniry:");
	while (scanf("%d", &num))
	{
		to_baniry(num);
		printf("\n");
		printf("Please input a number to print baniry:");

	}


	return 0;
}
void to_baniry(int num)
{
	if (num > 1)
	{	
		to_baniry(num / 2);
		printf("%d", num % 2);
	}
	else
	{
		printf("%d", 1);
	}
}