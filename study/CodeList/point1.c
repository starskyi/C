#include <stdio.h>

int main(void)

{
	int arr1[] = { 10,11,12 };

	int arr2[][2] = { {11,12},{13,14} };

	int* p1;
	int** p2;
	int(*p3)[2];

	p1 = &arr1;
	p2 = &p1;
	p3 = &arr2[0][0];

	printf("%p %p \n", arr1, p1);
	printf("%p %p \n", &arr1[1], p1 + 1);

	printf("%p \n", p2);
	printf("%p %p \n", arr2, p3);
	printf("%p %p\n", arr2 + 1, p3 + 1);
	printf("%p %d\n", &arr2[1][0], *(*(arr2+1) + 1));

	 
	return 0;
}