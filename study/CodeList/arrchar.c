#include <stdio.h>
#define ROW 6
#define COLUMN 40

int main(void)
{
	char *arr1[ROW] = { "hello", "world", "wellcome", "to", "my", "world" };
	char arr2[ROW][COLUMN] = { "hello", "world", "wellcome", "to", "my", "world" };
	
	printf("%c %c\n", *(*(arr1 + 1) + 2), arr2[1][2]);
	int i;
	for (i = 0; i < ROW; i++)
	{
		printf("%-20s %-20s %d %d\n", arr1[i], arr2[i], sizeof(arr1[i]), sizeof(arr2[i]));
	}


	return 0;
}