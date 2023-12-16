#include <stdio.h>

void converse(int* arr, int n);
void converse1(int arr[], int n);
int main(void)
{

	int arr[] = { 1,2,3,4,5,6,7,8,9 };
	int n = sizeof(arr) / sizeof(int);
	//converse(arr, n);
	converse1(arr, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
void converse(int* arr, int n)
{
	int i = n / 2;
	int* p = arr;
	while (i > 0)
	{
		int temp;
		temp = *p;
		*p = *(p + n - 1);
		*(p + n - 1) = temp;
		p++;
		n -= 2;
		i--;
	}
}
void converse1(int arr[], int n)
{
	int i;
	int n1 = n / 2;
	for (i = 0; i < n1; i++)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}
}