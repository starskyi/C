#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void fibonacci(int time);
int fibonacci2(int time);
int main(void)
{
	int time;
	printf("Please input a number(input q to exit):");

	while (scanf("%d", &time))
	{
		fibonacci(time);
		printf("\n%d\n", fibonacci2(time));

		printf("Please input a number(input q to exit):");
	}


	return 0;
}
void fibonacci(int time)
{
	long long cur_num,prev_num,prev_p_num;
	long long sum = 2;
	int i;
	if (time > 0) 
	{
		printf("%-10d %-10d %-10ld\n", 1, 1, 1);
		for (i = 2, cur_num = 1, prev_num = 1, prev_p_num = 0; i <= time; i++)
		{
			printf("%-10d %-10d %-10ld\n", i, cur_num, sum);
			prev_p_num = prev_num;
			prev_num = cur_num;
			cur_num = prev_num + prev_p_num;
			sum += cur_num;

		}
	}
	else 
	{
		printf("Please input other number\n");
	}
	
}
int fibonacci2(int time)
{
	if (time > 2)
	{
		int a = fibonacci2(time - 1) + fibonacci2(time - 2);
		return a;
	}
	
	else
	{
		return 1;
	}
}

