#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>

extern unsigned int srand1(unsigned int seed);
int main(void)
{
	int seed;
	puts("Please input a number as seed:");
	while (scanf("%d", &seed))
	{
		printf("%d\n", srand1(seed + time(0)));
		puts("Please input a number as seed:");
	}
	
	return 0;
}