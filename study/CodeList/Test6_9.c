#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define SIZE 8

int main(void)
{
	double arr1[SIZE], arr2[SIZE];
	double num;
	int i;

	for (i = 0, num = 0.0; i < SIZE; i++)
	{
		printf("Plese enter number for arr[%d]:", i);
		scanf("%lf", &arr1[i]);
		num += arr1[i];
		arr2[i] = num;
	}
	for (i = 0; i < SIZE; i++)
	{
		printf("%-8.2f", arr1[i]);
	}
	printf("\n");
	for (i = 0; i < SIZE; i++)
	{
		printf("%-8.2f", arr2[i]);
	}
}