#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "D:\\code\\book.txt"
#define MAXTIT 40
#define MAXAUT 40
#define MAXBOOKS 10


struct book {
	char title[MAXTIT];
	char author[MAXAUT];
	float price;
};

char* s_gets(char*, int);
int main(void)
{
	const size_t size = sizeof(struct book);
	struct book book1[MAXBOOKS];
	int count = 0;
	int filecount = 0;
	FILE* fp = NULL;
	if ((fp = fopen(FILENAME, "a+b")) == NULL)
	{
		printf("Cannot open file:%s", FILENAME);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", fp == NULL);
	rewind(fp);
	while (count < MAXBOOKS && fread(&book1[count], size, 1, fp) == 1)
	{
		if (count == 0)
		{
			printf("the book content is:\n");
		}
		printf("title: %s, author: %s, price: %.2f\n", book1[count].title, book1[count].author, book1[count].price);
		count++;
	}
	filecount = count;

	if (count == MAXBOOKS)
	{
		puts("the book.txt is full", stderr);
		exit(1);
	}
	printf("Now start to add book([enter] to quit )\n");


	printf("Please input the title: ");
	while (count < MAXBOOKS && s_gets(book1[count].title, MAXTIT) != NULL && book1[count].title[0] != '\0')
	{
		printf("Please input the author: ");
		s_gets(book1[count].author, MAXAUT);
		printf("Please input the price: ");
		scanf("%f", &book1[count].price);
		count++;
		while (getchar() != '\n')
			continue;
		if (count == MAXBOOKS)
		{
			printf("the book.txt is full\n");
		}
		else
		{
			puts("star to input the next book:([enter] to quit )");
			printf("Please input the title: ");
		}
	}
	
	if (count > 0)
	{
		printf("your books is:");
		for (int i = 0; i < count; i++) {
			printf("%-10s %-10s %-10.2f\n", book1[i].title, book1[i].author, book1[i].price);
		}
		fwrite(&book1[filecount], size, count - filecount, fp);
	}
	printf("bye\n");

	return 0;
}
char* s_gets(char* chs, int n)
{
	char* ret_val;
	char* find;
	if ((ret_val = fgets(chs, n, stdin)))
	{
		find = strchr(chs, '\n');
		if(find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ret_val;
}