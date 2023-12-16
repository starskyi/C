#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	int ch;
	int up_count = 0, low_count = 0;

	printf("Please enter letters:");

	while ((ch = getchar()) != EOF)
	{
		if (isupper(ch))
		{
			up_count++;
		}
		else if(islower(ch))
		{
			low_count++;
		}
		
	}
	printf("\nupper letters have %d and lower letters have %d\n", up_count, low_count);
}