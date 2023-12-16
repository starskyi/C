#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void)
{
	char str[50];
	char ch;
	int i = 0;
	
	scanf("%c", &ch);

	while (ch != '\n')
	{
		str[i] = ch;
		scanf("%c", &ch);
		i++;
	}
	
	for (i = i-1; i >=0 ; i--)
	{
		printf("%c", str[i]);
	}
	

}