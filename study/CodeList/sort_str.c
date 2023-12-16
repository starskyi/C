#include <stdio.h>
#include <string.h>
#define ROW 5
#define COLUMN 40

char* s_gets(char* st, int n);
void strsort(char *st[], int n);
int main(void)
{
	char arr1[ROW][COLUMN];
	char *temp[COLUMN];

	int i = 0;
	puts("Please input worlds:");
	while (s_gets(arr1[i], COLUMN) && i < ROW)
	{
		
		if (temp[0] == '\0')
			break;
		temp[i] = arr1[i];
		i++;
		if (i == ROW)
			break;
	}
	strsort(temp, i);
	int j;
	for (j = 0; j < i; j++)
	{
		puts(temp[j]);
		
	}
	
	return 0;
}

void strsort(char *arr1[COLUMN], int n)
{
	
	int i, j;
	char *temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(arr1[i], arr1[j]) > 0)
			{
				temp = arr1[i];
				arr1[i] = arr1[j];
				arr1[j] = temp;
			}
			
		}
	}
}

char* s_gets(char* st, int n)
{
	char* st1;
	int i = 0;
	if ((st1 = fgets(st, n, stdin)))
	{
		while (st[i] != '\n' && st[i] != '\0')
		{
			i++;
		}
		if (st[i] == '\n')
			st[i] = '\0';
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
}