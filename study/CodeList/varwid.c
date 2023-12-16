#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)   //printf() scanf() ÐÞÊÎ·û*µÄÓÃ·¨
{
	unsigned width, precision;
	float num = 256.3f;
	int n;
	char ch[30];


	printf("%d\n", num);
	printf("Please input the filed width:");
	scanf("%d", &width);
	printf("%*d\n", width, num);
	printf("Please input the filed width and precision:");
	scanf("%d %d", &width, &precision);
	printf("%*.*f\n", width, precision, num);
	printf("%f", num);

	printf("Please input three number:");
	scanf("%*d %*d %d", &n);					
	printf("The last number is: %d\n", n);

	return 0;
}