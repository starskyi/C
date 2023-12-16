#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

double power1(double num, int power);
double power2(double num, int power);

int main(void)
{
	double num;
	int power;

	printf("Please input two number(input q to exit):");

	while (scanf("%lf %d", &num, &power) == 2)
	{
		printf("%.2f\n", power2(num, power));
		printf("Please input two number(input q to exit):");
	}

	return 0;
}

double power1(double num, int power)
{
	int i;
	double sum;

	if (power == 0)
		return 1;
	if (num == 0)
		return 0;
	if (power == 1)
		return num;
	
	for (i = 1, sum = num; i < abs(power); i++)
	{
		sum *= num;
	}
	return sum;
}

double power2(double num, int power)
{
	if (power == 0)
		return 1;
	if (num == 0)
		return 0;
	if (power == 1)
		return num;
	if (abs(power) > 1)
	{
		return num * power2(num, --power);
	}
	return num;

}