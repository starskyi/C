#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define SIZE 8

int main(void)
{
	
	int arr[SIZE];
	int i;

	for (i = 1, arr[0] = 1; i < SIZE; i++)
	{
		arr[i] = arr[i - 1] * 2;
	}

	i = 0;
	do
	{
		printf("%d ", arr[i]);
		i++;
	} while (i < SIZE);
}