#include <stdio.h>
#include <ctype.h>
#define SIZE 40
char * get_word(char *);
int main(void)
{
	char word[SIZE];
	puts("Please input a word:");
	
	while (1)
	{
		char* chs = get_word(word);
		puts(chs);
		puts("Please input a word:");
		
	}
	return 0;
}
char * get_word(char * word)
{
	
	char ch;
	while (isspace((ch = getchar())))
		continue;
	word[0] = ch;
	int i = 1;
	while (!isspace((ch = getchar())))
	{
		*(word + i) = ch;
		i++;
	}
	*(word + i) = '\0';
	if (ch == '\n')
		return word;
	while (getchar() != '\n')
		continue;
	return word;
}