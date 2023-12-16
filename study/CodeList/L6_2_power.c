#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

double power(double n, int p);
int main(void)
{
	double n;
	int p;

	printf("Please enter a number and the positive integer power:");
	while (scanf("%lf %d", &n, &p))
	{
		printf("%.2f\n", power(n, p));
		printf("Please enter a number and the positive integer power:");
	}
	

	return 0;
}

double power(double n, int p)
{
	int i;
	double value = 1;
	for (i = 0; i < p; i++)
	{
		value *= n;
	}
	return value;

}