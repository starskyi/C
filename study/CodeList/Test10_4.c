#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define SIZE 40

int addarr(int*, int);
int max(int*, int);
int main(void)
{
	int nums[SIZE];
	int n;
	puts("Please input numbers(q to quit):");
	n = addarr(nums, SIZE);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n%d \n", max(nums, n));
	return 0;
}
int addarr(int* num, int n)
{
	int nu;
	int i = 0;
	while (scanf("%d", &nu) && i < n)
	{
		*(num + i++) = nu;
	}
	return i;
}
int max(int* num, int n)
{
	int temp = *num;
	for (int i = 1; i < n; i++)
	{
		if (temp < *(num + i))
		{
			temp = *(num + i);
		}
	}
	return temp;
}

