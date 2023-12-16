#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>


int main(void)
{
	int count, i;
	double cur_num, fore_sum1, fore_sum2, cur_sum1, cur_sum2;
	printf("Please enter the count:");
	while(scanf("%d", &count))
	{
		for (i = 0, cur_num = 1, fore_sum1 = 1,fore_sum2 = 1; i < count; i++)
		{
			cur_num /= 2;
			cur_sum1 = fore_sum1 + cur_num;
			cur_sum2 = fore_sum2 - cur_num;
			fore_sum1 = cur_sum1;
			fore_sum2 = cur_sum2;
		}
		printf("1 + 1/2 + 1/4 + ...... = %f\n", cur_sum1);
		printf("1 - 1/2 - 1/4 - ...... = %f\n", cur_sum2);
		
		printf("Please enter the count:");
	}
}