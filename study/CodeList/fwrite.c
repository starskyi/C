#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
int main(void)
{
	int price[SIZE] = {10, 20, 30, 50, 60, 70 ,90, 100, 200};
	FILE *fp1, *fp2;
	if ((fp1 = fopen("a.txt", "w")) == NULL)
	{
		puts("Cannot open file \"a.txt\"");
		exit(EXIT_FAILURE);
	}
	fwrite(price, sizeof(int), SIZE, fp1);
	fclose(fp1);
	
	if ((fp2 = fopen("a.txt", "r")) == NULL)
	{
		puts("Cannot open file \"a.txt\"");
		exit(EXIT_FAILURE);
	}
	int a = fread(price, sizeof(int), SIZE, fp2);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%f ", price[i]);
	}
	printf("\n");
	printf("%d\n", a);
	fclose(fp2);
	return 0;
}