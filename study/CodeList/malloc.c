#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	int* arr;

	puts("Please input the array size:");
	scanf("%d", &n);
	arr = (int*)malloc(n * sizeof(int));
	printf("%zd\n", sizeof(arr));
	for (int i = 0; i < n; i++)
		arr[i] = i;
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
	free(arr);
	return 0;
}

