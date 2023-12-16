#include <stdio.h>

int main(void)
{
	int  a = 2147483647;
	float fl = -3.4e38f;
	float fh = 3.4e38f;
	
	printf("int a = %d ; a + 1 = %d; a + 2 = %d\n", a, a + 1, a + 2);
	printf("float fl = %f ; a / 2 = %f; a * 2 = %f\n", fl, fl / 2, fl * 2);
	printf("float fh = %f ; a / 2 = %f; a * 2 = %f\n", fh, fh / 2, fh * 2);

	return 0;
}