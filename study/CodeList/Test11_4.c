#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#define SIZE 40
#define WORDS 2

char* find_words(char*, char);
bool get_words(char* words[], int n);
void print_arr(char* arr[], int n);
int main(void)
{
	char chs1[SIZE];
	char *chs2[WORDS];
	char ch;
	char* p;
	printf("Please input two words:\n");
	while (get_words(chs2, WORDS))
	{
		p = find_words(chs2, *(chs2 + 1));
		printf("%p %c\n", p, *p);
		printf("Please input two words:\n");
	}
	
	/*while (scanf("%s %s", chs1, &ch) == 2)
	{
		printf("%d", getchar());
		p = find_words(chs1, ch);
		printf("%c %p\n", *p, p);
		printf("Please input two words:\n");
	}*/

	return 0;
}

char* find_words(char* chs1, char ch)
{
	int i = 0;
	while (*chs1 != '\0')
	{
		if (*(chs1 + i) == ch)
		{
			return (chs1 + i);
		}
		i++;
	}
	return NULL;
}

bool get_words(char *words[], int n)
{
	char ch;
	int num = 0;
	int i = 0;
	char prev = '\n';
	char *p = words;
	
	while (num < n && (ch = getchar()))
	{
		if (ch == '\n' && prev == '\n')
			return false;
		if (!isspace(ch))
		{
			
			*(p + i) = ch;
			i++;
		}
		if (isspace(ch) && !isspace(prev))
		{
			
			*(p + i) = '\0';
			i = 0;
			p = words+1;
			num++;
		}
		prev = ch;
	}
	return true;
}
void print_arr(char* ch[], int n)
{
	int i = 0;
	while (i < n)
	{
		printf("%s\n", ch+i);
		i++;
	}
}