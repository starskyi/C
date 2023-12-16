#include <stdio.h>
#include <time.h>
#define SIZE 100

int main(void)
{
	int *num[SIZE];
	int* num2[SIZE];
	srand((unsigned)time(NULL));

	puts("=================");
	for (int i = 0; i < SIZE; i++)
	{
		*(num + i) = rand() % 9 + 1;
		printf("%d ", *(num + i));
	}
	printf("\n");
	puts("===================");
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (num[i] > num[j])
			{
				
				int temp = num[i];
				num[i] = num[j];
				num[j] = temp;

			}
			
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", num[i]);
	}
	printf("\n");
	puts("=======================");
	return 0;
}