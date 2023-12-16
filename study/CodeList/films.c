#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

char* s_gets(char* chs, int n);
void showItem(Item* item);
int main(void)
{
	List movies;
	Item item;

	InitializeList(&movies);

	if (ListIsFull(&movies))
	{
		fprintf(stderr, "No memory available bye\n");
		exit(EXIT_FAILURE);
	}

	puts("Please inpute the movie title:");

	while (s_gets(item.title, TSIZE) && item.title[0] != '\0')
	{
		
		puts("Please inpute the rating(1 - 10):");
		while (scanf("%d", &item.rating) != 1)
		{
			while (getchar() != '\n')
				continue;
			puts("Please inpute the rating(1 - 10):");
		}
		while (getchar() != '\n')
			continue;
		if (AddItem(item, &movies))
		{
			printf("Success add!\n");
			puts("Please inpute the next movie title:");
		}
		else
		{
			puts("Failed add");
			puts("Please inpute the movie title:");
		}
		if (ListIsFull(&movies))
		{
			fprintf(stderr, "the List is full\n");
			break;
		}
	}

	printf("The List has %u movies in total\n", ListItemCount(&movies));

	Traverse(&movies, showItem);

	EmptyList(&movies);

	return 0;
}

void showItem(Item* item)
{
	printf("Title: %s, rating: %d\n", item->title, item->rating);
}

char* s_gets(char* chs, int n)
{
	char* ch_val;
	char* find;
	ch_val = fgets(chs, n, stdin);
	if (ch_val)
	{
		find = strchr(chs, '\n');
		if (find)
		{
			*find = '\0';
		}
		else
		{
			while (getchar() != '\n')
				continue;
		}
	}
	return ch_val;
}