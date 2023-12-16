#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	FILE* fp;

	if (argc == 1)
	{
		fp = stdin;
		printf("Please input numbers(q to quit):\n");
	}
	else if(argc == 2)
	{
		fp = fopen(argv[1], "r");
	}
	else
	{
		printf("Usage:%s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	double num = 0;
	double sum = 0;
	int count = 0;
	while ((fscanf(fp, "%lf", &num)) == 1)
	{
		sum += num;
		count++;
	}

	fclose(fp);
	if (count > 0)
	{
		printf("Average of %d values is %.2f\n", count, sum / count);
	}
	else
	{
		printf("No more valid data\n");
	}
	return 0;
}