#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define SIZE 40
int main(void)
{
	FILE* fp;
	char word[SIZE];
	if ((fp = fopen("word.txt", "a+")) == NULL)
	{
		fprintf(stdout, "Cannot open file %s\n", "word.txt");
		exit(EXIT_FAILURE);
	}
	puts("Please input words(input '#' to quit in the first of new line):");
	while ((fscanf(stdin, "%s", word) == 1 && word[0] != '#'))
	{
		fprintf(fp, "%s ", word);
	}
	fprintf(stdout, "File content is:\n");
	fseek(fp, 0L, SEEK_SET);
	while (fscanf(fp, "%s", word) == 1)
	{
		fprintf(stdout, "%s ", word);
	}
	printf("\n");
	printf("Done!\n");
	if (fclose(fp) != 0)
	{
		fprintf(stdout, "%s\n", "Error closing file");
		exit(EXIT_FAILURE);
	}

	return 0;
}