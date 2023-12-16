#include <stdio.h>

void change(int* a, int* b);
int main(void)
{
	int a = 10;
	int b = 20;
	
	printf("%d %d\n", a, b);
	printf("%p %p\n", &a, &b);
	printf("%p %p\n", &a, &b);
	change(&a, &b);
	printf("%d %d\n", a, b);


	return 0;
}

void change(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}