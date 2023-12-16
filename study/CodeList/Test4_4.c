#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	const double rateg = 3.785, ratem = 1.609;
	double mileage, oilcsum;
	
	printf("Please input the mileage(mile) and oilcsum(gallon):");
	scanf("%lf %lf", &mileage, &oilcsum);
	printf("%f %f %f\n", mileage, oilcsum, mileage / oilcsum);
	printf("your speed is %.1f mile/oilcsum (%.1f L/km)\n", mileage / oilcsum, (oilcsum*rateg)/(mileage*ratem));

	return 0;
}