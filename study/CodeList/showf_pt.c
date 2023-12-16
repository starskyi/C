#include <stdio.h>

int main(void)   //以两种方式显示float 类型的值
{
	float aboat = 32000.0;
	double abet = 2.14e9;
	long double dip = 5.32e-5;
	printf("%f can be written %e.\n", aboat, aboat);
	printf("And it's %a in hexadecimal, powers of 2 notation\n", abet, abet);
	printf("%f can be written %e.\n", abet, abet);
	printf("%Lf can be written %Le", dip, dip);
	return 0;
}