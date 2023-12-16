#include <stdio.h>

/* int main(void)
{
	double n1 = 3.0;
	double n2 = 5.0;
	long n3 = 2000000000;
	long n4 = 1234567890;

	printf("%.1e %.1e %.1e %.1e %f\n", n1, n2, n3, n4, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
	printf("%zd %zd %zd %zd\n", sizeof(n1), sizeof(n2), sizeof(n3), sizeof(n4));

	return 0;
} */
int main(void)
{
	long n4 = 1234567890;
	long n3 = 2000000000;
	double n2 = 3.0;
	float n1 = 3.0;
	printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);
	printf("%ld %ld %ld %ld\n", n4, n3, n2, n1);
	return 0;
}