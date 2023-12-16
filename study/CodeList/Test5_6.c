#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	int curmoney = 0, totmoney = 0;
	int curdays = 0, totdays = 0;

	printf("Please enter days of you total earn:");
	scanf("%d", &totdays);

	while (totdays > 0)
	{
		printf("%-20s %-20s %-20s\n", "days", "earn money today", "earn money total");
		while (++curdays <= totdays)
		{
			curmoney = curdays*curdays ;
			totmoney = totmoney + curmoney;
			printf("  %3d %20d %20d\n", curdays, curmoney, totmoney);
		}

		printf("Please enter days of you total earn:");
		scanf("%d", &totdays);

	}

	return 0;
}