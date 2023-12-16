#include <stdio.h>

void look(int num1);
int main(void)
{
	int num1 = 2,num2 = 5;

	printf("%d %p\n", num1, &num1);
	printf("%d %p\n", num2, &num2);
	look(num1);
	return 0;
}

void look(int num1)
{
	int num2 = 10;
	printf("%d %p\n", num1, &num1);
	printf("%d %p\n", num2, &num2);
}