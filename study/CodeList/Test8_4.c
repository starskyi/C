#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#define SPACE ' '

int ave_letter(int ch);
int main(void)
{
	int ch;
	double words_count = 0,letter_count = 0;
	int prev = '\n';

	while ((ch = getchar()) != EOF)
	{
		if (isalpha(ch))
		{
			letter_count++;
		}
		if (ch == SPACE || ch == '\n')
		{
			if (!isspace(prev))
			{
				words_count++;
			}
		}
		prev = ch;
		
	}
	printf("have %d words and average letters of words is %.1f\n", (int)words_count, letter_count / (words_count == 0 ? 1 : words_count));

	return 0;
}

