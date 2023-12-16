#include <stdio.h>
#define SIZE 10
int main(void)
{
	char arr[SIZE];

	puts("Plese enter text:");
	while (fgets(arr, SIZE, stdin) != NULL && arr[0] != '\n')
	{
		fputs(arr, stdout);
	
	}

	return 0;
}