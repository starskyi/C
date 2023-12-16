#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main(void)
{
	double tempc,tempf,tempk;
	int a = 1;
	printf("Please input temprature(F):");
	scanf("%lf", &tempf);
	while (a)
	{
		tempc = (tempf - 32)/1.8;
		tempk = tempc + 273.16;
		printf("%.2fF %.2fC %.2fK\n", tempf, tempc, tempk);

		printf("Please input temprature(F):");
		
	    a = scanf("%lf", &tempf);
		
	}
	return 0;
}