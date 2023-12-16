#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int age;
	float score;
	char name[40];

	printf("Please input your age and score:");
	scanf("%d %f", &age, &score);
	printf("Please input your name:");
	scanf("%s", name);
	printf("Hello %s! Your age is %d and score is %.2f", name, age, score);
	return 0;
}