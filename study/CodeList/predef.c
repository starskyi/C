#include <stdio.h>

int main(void)
{

	printf("%s\n", __FILE__);
	//printf("%ld\n", __STDC_VERSION__);
	printf("%s\n", __DATE__);
	printf("%s\n", __TIME__);
	printf("%s\n", __LINE__);
	return 0;
}