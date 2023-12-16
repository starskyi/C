#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 40
#define LEN 4
enum color { red, orange, yellow, violet };
const char* colors[] = {"red", "orange", "yellow", "violet"};

char* s_gets(char*, int);
int find_index(char* colors[], char* chs, int n);
int main(void)
{
	char chs[SIZE];
	int index = -1;
	
	puts("Please input the color:");
	while ((s_gets(chs, SIZE)) && chs[0] != '\0')
	{
		index = find_index(colors, chs, LEN);

		switch (index)
		{
		case red:
			printf("you select color is %s and index is %d\n", colors[index], index);
			break;
		case orange:
			printf("you select color is %s and index is %d\n", colors[index], index);
			break;
		case yellow:
			printf("you select color is %s and index is %d\n", colors[index], index);
			break;
		case violet:
			printf("you select color is %s and index is %d\n", colors[index], index);
			break;
		default:
			puts("no such a color");
			break;
		}
	}
	

	return 0;
}
char* s_gets(char* chs, int n)
{
	char* ret_val;
	char* find;
	if ((ret_val = fgets(chs, n, stdin)))
	{
		find = strchr(chs, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}

int find_index(char* colors[], char* chs, int n)
{
	int i = 0;
	while (i < n)
	{
		if (strcmp(colors[i], chs) == 0)
			return i;
		i++;
	}
	return -1;
}
