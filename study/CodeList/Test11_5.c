#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#define WORDS 2


bool get_words(char *chs[], int n);
bool is_within(char* chs, char ch);
int main(void)
{
	char* words[WORDS];
	puts("Please input two words:");
	while (get_words(words, WORDS))
	{
		bool flag = is_within(words, *(words + 1));
		printf("%d\n", flag);
		puts("Please input two words:");

	}

	//printf("%s %s\n", words, words + 1);
	return 0;
}

bool get_words(char* chs[], int n)
{
	char* p = chs;
	char ch;
	char prev = '\n';
	int num = 0;
	int i = 0;

	while ((ch = getchar()))
	{
		if (ch == '\n' && prev == '\n')
			return false;

		if (!isspace(ch))
		{
			if (num == 1) {
				*p = ch;
				*(p + 1) = '\0';
				if (getchar() != '\n')
				{
					while (getchar() != '\n')
						continue;
				}
				return true;
			}
			*(p + i) = ch;
			i++;
		}
		if (isspace(ch) && !isspace(prev))
		{
			*(p + i) = '\0';
			p = chs + 1;
			num++;
		}
		prev = ch;
	}
	return true;
}
bool is_within(char* chs, char ch)
{
	int i = 0;
	while (*(chs + i) != ch)
	{
		if (*(chs + i) == '\0')
			return false;
		i++;
	}
	return true;
}