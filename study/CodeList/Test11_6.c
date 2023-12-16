#include <stdio.h>
#include <ctype.h>
#define SIZE 40

int get_arr(char* chs, int n);
char* mystr_cmp(char* chs1, char* chs2, int n);
int main(void)
{
	char arr1[SIZE];
	char arr2[SIZE];
	puts("Please input string:");
	while (get_arr(arr1, SIZE))
	{

		mystr_cmp(arr2, arr1, 10);
		printf("%s\n", arr1);
		printf("%s\n", arr2);
		puts("Please input string:");
	}
	
	return 0;
}
char* mystr_cmp(char chs1[], char chs2[], int n)
{
	int i = 0;
	while (i < n)
	{
		if (*(chs2 + i) == '\0')
		{
			*(chs1 + i) = '\0';
			return chs1;
		}
		*(chs1 + i) = *(chs2 + i);
		if (i == n - 1)
		{
			*(chs1 + n) = '\0';
		}
		i++;
	}
	return chs1;
}
int get_arr(char* chs, int n)
{
	char ch;
	int i = 0;
	while (isspace((ch = getchar())) && ch != '\n')
		continue;
	if (ch == '\n')
		return 0;
	*(chs + i) = ch;
	i++;
	while ((ch = getchar()) && i < n - 1)
	{
		if (ch == '\n')
		{
			*(chs + i) = '\0';
			return 1;
		}
		*(chs + i) = ch;
		i++;
	}
	return 1;
}
