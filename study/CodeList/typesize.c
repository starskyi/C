#include <stdio.h>

int main(void)
{
	printf("Type char has a size of %zd bytes.\n", sizeof(char));
	printf("Type short has a size of %zd bytes.\n", sizeof(short));
	printf("Type int has a size of %zd bytes.\n", sizeof(int));
	printf("Type float has a size of %zd bytes.\n", sizeof(float));
	printf("Type long has a size of %zd bytes.\n", sizeof(long));
	printf("Type double has a size of %zd bytes.\n", sizeof(double));
	printf("Type long long  has a size of %zd bytes.\n", sizeof(long long));
	printf("Type long double has a size of %zd bytes.\n", sizeof(long double));
	printf("%f  %.10f.\n", 12.123456789, 12.123456789);
	printf("\n %.9f", 1.123456789);
	
	

	return 0;
}