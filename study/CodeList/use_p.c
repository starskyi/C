#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "queue.h"

int main(void)
{
	Queue line;
	Item item;
	char ch;

	InitQueue(&line);
	printf("a) add \nb) remove\nc) show\n\n>>");
	while ((ch = getchar()) != '\n')
	{
		while (getchar() != '\n')
			continue;
		if (ch == 'a')
		{
			printf("input Integer to add:\n");

			while (scanf("%d", &item) != 1)
			{
				printf("input Integer to add:\n");
				while (getchar() != '\n')
					continue;
			}
			while (getchar() != '\n')
				continue;

			printf("add %d to Queue\n", item);
			if (EnQueue(item, &line))
			{
				printf("add success\n\n");
			}
			else
			{
				printf("add fialed\n\n");
			}
			
			
		}
		else if (ch == 'b')
		{
			DelQueue(&item, &line);
			printf("remove %d from Queue\n", item);
		}
		else if (ch == 'c')
		{
			ShowQueue(&line);
		}
		else
		{
			printf("Please input a or b\n");
		}
		printf("a) add \nb) remove\nc) show\n\n>>");
	}

	EmptyQueue(&line);
}

