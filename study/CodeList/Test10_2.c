#include <stdio.h>

void copy_arr1(int arr1[], int arr2[], int n);
void copy_arr2(int *arr1, int *arr2, int n);
void print_arr(int arr[], int n);
int main(void)
{
	
	int arr1[] = { 1,2,3,4,5,6,7,8 };
	int n = sizeof(arr1) / sizeof(int);
	int arr2[8];
	int i;

	copy_arr2(arr1, arr2, n);
	print_arr(arr1, n);
	print_arr(arr2, n);
	return 0;

}
void print_arr(int arr[], int n)
{
	int i;
	printf("[");
	for (i = 0; i < n - 1; i++)
	{
		printf("%d, ", arr[i]);
	}
	printf("%d]\n", arr[n - 1]);
	
}
void copy_arr1(int arr1[], int arr2[], int n)
{

	int i;
	for (i = 0; i < n; i++)
	{
		arr2[i] = arr1[i];
	}
}
void copy_arr2(int *arr1, int *arr2, int n)
{

	int i;
	for (i = 0; i < n; i++)
	{
		*(arr2 + i) = *(arr1 + i);
	}
	
}