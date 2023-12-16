#include <stdio.h>

int main(void)
{
	const double RENT = 500.0;

		printf("*%f*\n", RENT);
		printf("*%15f*\n", RENT);
		printf("*%015f*\n", RENT);
		printf("*%015.3f*\n", RENT);
		printf("*%-15.3f*\n", RENT);
		printf("*%3.2f*\n", RENT);

	return 0;
}