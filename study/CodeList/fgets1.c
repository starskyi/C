#include <stdio.h>
#define SIZE 10
int main(void)
{
	char arr[SIZE];

	puts("Please enter message:");
	fgets(arr, SIZE, stdin);
	puts(arr);
	fputs(arr, stdout);
	fputs(arr, stdout);
	
	return 0;
}