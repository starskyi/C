#include <stdio.h>
#include <string.h>
#define SIZE 40
#define ST "hello world"

char* s_gets(char* st, int n);
int main(void)
{
	char st[SIZE];

	puts("Please input string to competition:");

	while (s_gets(st, SIZE))
	{
		
		//while(strcmp(st, ST) != 0)
		while(strncmp(st, ST, 5))
		{
			puts("Failed, Please try again:");
			s_gets(st, SIZE);
		}
		
		puts("Right, congratulations!");
		puts("Please input string to competition:");

	}

	return 0;
}

char* s_gets(char* st, int n)
{
	char* st1;
	st1 = fgets(st, n, stdin);
	int i;
	if (st1)
	{
		i = 0;
		while (st1[i] != '\n' && st1[i] != '\0')
		{
			i++;
		}
		if (st1[i] == '\n')
			st1[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
			
	}
	return st1;
}