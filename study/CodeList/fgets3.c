#include <stdio.h>
#define SIZE 6
int main(void)
{
	char arr[SIZE];
	int i;
	
	puts("Plese enter text:");
	
	while (fgets(arr, SIZE, stdin) != NULL && arr[0] != '\n')
	{
		i = 0;
		while (arr[i] != '\n' && arr[i] != '\0')
		{
			i++;
			continue;

		}
		if (arr[i] == '\n')
		{
			arr[i] = '\0';
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
		puts(arr);
	}

	return 0;
}