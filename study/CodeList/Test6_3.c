#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	
	char ch;
	scanf("%c", &ch);
	while (ch != 'g')
	{
		printf("%c", ch);
		scanf("%c", &ch);
	}

	return 0;
}