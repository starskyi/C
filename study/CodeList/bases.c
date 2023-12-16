#include <stdio.h>

int main(void)   //使用十六进制，八进制分别打印100
{
	int num = 100;
	printf("十进制num = %d, 八进制num = %o, 十六进制num = %x", num, num, num);
	printf("十进制num = %d, 八进制num = %#o, 十六进制num = %#x", num, num, num);

	return 0;
}