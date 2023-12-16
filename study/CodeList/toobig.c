#include <stdio.h>

int main(void)
{
	int a = 2147483647;
	unsigned int ua = 4294967295;
	short b = 32767;

	printf("a = %d\na + 1 = %d\na + 2 = %d\n", a, a + 1, a + 2);
	printf("ua = %u\nua + 1 = %u\nua + 2 = %u\n", ua, ua + 1, ua + 2);
	

	return 0;
}