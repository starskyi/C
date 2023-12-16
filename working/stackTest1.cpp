#include <iostream>

int test(int a, int b, int c)
{
	int e = 0;
	int d = 2;
	e = a + 1;
	d = c + 1;
	return e;
}

int main1()
{
	printf("begin\n");
	int a = 0;
	a = test(1, 2, 3);
	printf("end\n");
	return 0;
}