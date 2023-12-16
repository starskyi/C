#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define RATE 0.39

int main(void)
{
	int hight;

	printf("Please enter a hight in centimeters:");
	scanf("%d", &hight);

	while (hight > 0)
	{
		printf("Your hight is %d in centimeters, %.2f in inch\n", hight, hight * RATE);
		printf("Please enter a hight in centimeters:");
		scanf("%d", &hight);

	}

	return 0;
}