#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int main(void)
{
	int i;
	char chs[40];

	printf("Please enter a word (exit):");
	scanf("%s", chs);
	while (strcmp(chs, "exit"))
	{
		for (i = strlen(chs) - 1; i >= 0; i--)
		{
			printf("%c ", chs[i]);
		}
		
		printf("\nPlease enter a word (exit):");
		scanf("%s", chs);
	}

}