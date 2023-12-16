#include <stdio.h>
#include <ctype.h>
#define SIZE 40
#define STRS 2

void get_strs(char* strs[], int n);
char* find_char(char* ch1, char* ch2);
int main(void)
{
	char chs[2][40];
	while (1)
	{
		get_strs(chs, STRS);
		printf("%p %s\n", chs, chs);
		printf("%p %s\n", chs + 1, chs + 1);
		char* ch = find_char(chs, chs + 1);
		printf("%s\n", ch);
	}
	
	return 0;
}

char* find_char(char* ch1, char* ch2)
{
	int i = 0;
	int j = 0;
	int previ;

	while (1)
	{
		if (*(ch2 + j) == '\0' || *(ch1 + i) == '\0')
			return NULL;
		if (*(ch1 + i) != *ch2)
		{
			i++;
			continue;
		}
		previ = i;
		while (*(ch1 + i) == *(ch2 + j) && *(ch2 + j) != '\0' && *(ch1 + i) != '\0')
		{
			j++;
			i++;
		}
		
		if (*(ch2 + j) == '\0')
			return ch2;
		else
		{
			j = 0;
			i = previ + 1;
		}
	}
	
	

}

void get_strs(char* strs[], int n)
{
	

	char *chs = strs;
	char ch;
	int i = 0;
	int num = 1;

	while (isspace(ch = getchar()))
		continue;
	*(chs + i) = ch;
	i++;
	while ((ch = getchar()))
	{
		if (ch == '\n' )
		{
			*(chs + i) = '\0';
			if (num == n)
			{
				return;
			}
			chs = strs + 5;
			num++;
			i = 0;
			while (isspace(ch = getchar()))
				continue;
			*chs = ch;
			i++;
			continue;
		}

		*(chs + i) = ch;
		i++;

	}

}