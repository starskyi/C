#include <stdio.h>

int main(void)
{
	int num = 1;
	while ( num <= 20 )
	{
		printf("%-6d %-6d\n", num, num * num);
		num++;
	}


	return 0;
}