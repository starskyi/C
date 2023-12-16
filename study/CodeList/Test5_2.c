#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define RATE 60
int main(void)
{
	int minute;;

	printf("Please inpute the time in minutes:");
	scanf("%d", &minute);
	while (minute > 0)
	{
		printf("%d : %d\n", minute / RATE, minute % RATE);
		printf("Please inpute the time in minutes:");
		scanf("%d", &minute);

	}

	return 0;
}