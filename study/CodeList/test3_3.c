#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	float quart;
	short age;
	float a = 1.123456789f;
	printf("%f   %e   %a\n", a, a, a);

	//计算年龄秒数
	printf("Please input your age:");
	scanf("%hd", &age);
	printf("your age is %hd and equals %d of seconds\n", age, age * 365 * 24 * 60 * 60);

	//计算对应夸脱水分子数
	printf("Please input the woter's quart number:");
	scanf("%f", &quart);
	printf("%f quart have %e woter molecule number\n", quart, quart*950 / 3.0e-23);

	return 0;
}