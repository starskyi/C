#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define STOP '|'

int main(void)
{
	unsigned int n_word= 0, n_line = 0, n_chars = 0, p_lien = 0;
	char ch;
	char prev = '\n';
	
	printf("enter text to analyzed(enter '|' to exit):\n");

	while ((ch = getchar()) != STOP)
	{
		n_chars++;
		if (isspace(ch) && !isspace(prev) )
		{
			n_word++;
		}
		prev = ch;
		if (ch == '\n' && n_chars > 0)
		{
			n_line++;
			n_chars--;
		}
	}
	if (ch == STOP && prev != '\n')
	{
		p_lien++;
	}
	if (!isspace(prev)) {
		n_word++;
	}
	printf("characters = %u, words = %u, lines = %u, partial lines = %u\n", n_chars, n_word, n_line, p_lien);

	return 0;
}