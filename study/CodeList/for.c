#include <stdio.h>

int main(void)
{
	int i;
	double sum,rate;
	for (i = 0, sum = 1, rate = 1; i < 10; i++)
	{
		rate /= 2;
		sum += rate;
		printf("%f\n", sum);

	}
	

	return 0;

}