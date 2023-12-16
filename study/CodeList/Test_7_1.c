#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS 1

int main(void)
{
	char ch;
	int spac_count = 0, linef_count = 0, chs_count = 0;

	printf("Please input text:");
	while ((ch = getchar()) != '#')
	{
		switch (ch)
		{
		case ' ': spac_count++;
			break;
		case '\n': linef_count++;
			break;
		default: chs_count++;
			break;
		}
	}
	printf("%d space, %d line feet, %d characters", spac_count, linef_count, chs_count);

	return 0;
}