#include <stdio.h>
#define SIZE 26

int main(void)
{
	char letters[SIZE];
	char letter = 'a';
	int i;

	for (i = 0; i < 26; i++)
	{
		letters[i] = letter;
		letter++;
	}

	for (i = 0; i < SIZE; i++)
	{

		printf("%c ", letters[i]);
	}

	return 0;
}