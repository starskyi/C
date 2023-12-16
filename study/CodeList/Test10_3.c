#include <stdio.h>
#define COLUMN 4

void copy_arr1(int arr1[], int arr2[], int n);
void copy_arr2(int* arr1, int* arr2, int n);
void print_arr(int arr[], int n);
int main(void)
{
	int arr1[][COLUMN] = { {1,2,3,4},{5,6,7,8}};
	int arr2[2][COLUMN];
	int row = sizeof(arr1) / sizeof(arr1[0]);
	
	int i;

	copy_arr1(arr1, arr2, 2);
	print_arr(arr1, 2);
	print_arr(arr2, 2);
	return 0;

}
void print_arr(int arr[][COLUMN], int row)
{
	int i,j;
	printf("[");
	for (i = 0; i < row; i++)
	{
		printf("[");
		for (j = 0; j < COLUMN; j++)
		{
			
			if (i != row - 1 && j == COLUMN - 1)
			{
				printf("%d]\n", arr[i][j]);
			}
			
			else if (i == row - 1 && j == COLUMN - 1)
			{
				printf("%d]]\n", arr[i][j]);
				return;
			}
			else
			{
				printf("%d, ", arr[i][j]);
			}
		}
		
	}
	
	

}
void copy_arr1(int arr1[][COLUMN], int arr2[][COLUMN], int row)
{

	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < COLUMN; j++)
		{
			arr2[i][j] = arr1[i][j];
		}
	}
}
void copy_arr2(int(* arr1)[COLUMN], int(* arr2)[COLUMN], int row)
{

	int i;
	for (i = 0; i < row*COLUMN; i++)
	{
		*(*arr2 + i) = *(*arr1 + i);

	}

}