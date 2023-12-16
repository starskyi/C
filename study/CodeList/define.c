#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
	printf("Some number limits for this system\n");
	printf("Biggist int is %d\n", INT_MAX);
	printf("Smallest long long is %lld\n", LLONG_MIN);
	printf("Biggist double is %e\n", DBL_MAX);
	printf("Biggist float is %e\n", FLT_MAX);

	return 0;
}