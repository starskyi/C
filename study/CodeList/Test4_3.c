#include <stdio.h>
#include <float.h>

int main(void)
{
	double d = 1.0 / 3.0;
	float f = 1.0 / 3.0;

	printf("%-17.6f %-17.6f %f\n", d, f, FLT_DIG);
	printf("%-17.12f %-17.12f %f\n", d, f, FLT_DIG);
	printf("%-17.16f %-17.16f %f\n", d, f, FLT_DIG);

	return 0;
}