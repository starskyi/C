#define _CRT_SECURE_NO_WARNIGS 1
#include <stdio.h>
#include <string.h>
#include "tree.h"

void addItem(Tree* pets);
void delItem(Tree* pets);
void show(Tree* pets);
char* s_gets(char* ch, int len);
void ShowItem(Item* item);
int main(void)
{
	
	char ch;

	Tree pets;
	InitTree(&pets);


	printf("a) add\nb) remove\nc) show\n\n>>");

	while ((ch = getchar()) != '\n')
	{
		while (getchar() != '\n')
			continue;

		switch (ch)
		{
		case 'a':
			addItem(&pets);
			break;
		case 'b':
			delItem(&pets);
			break;
		case 'c':
			show(&pets);
			break;
		default:
			printf("Please input a or b or c\n");
			break;
		}
		printf("a) add\nb) remove\nc) show\n\n>>");
	}
	DelAll(&pets);
	
}
void addItem(Tree* pets)
{
	Item item;
	bool flag;

	printf("Please input the pets name:\n");
	s_gets(item.petname, SLEN);
	printf("Please input the pet's kind:\n");
	s_gets(item.petkind, SLEN);

	flag = AddItem(item, pets);
	if (flag == true)
	{
		printf("%s %s	add success\n", item.petname, item.petkind);
	}
	else
	{
		printf("%s %s	add fialed\n", item.petname, item.petkind);
	}
}

void delItem(Tree* pets)
{
	Item item;
	bool flag;

	printf("Please input the pet's name:\n");
	s_gets(item.petname, SLEN);
	printf("Please input the pet's kind:\n");
	s_gets(item.petkind, SLEN);
	flag = DelItem(&item, pets);
	if (flag == true)
	{
		printf("%s %s	delete success\n", item.petname, item.petkind);
	}
	else
	{
		printf("%s %s	delete fialed\n", item.petname, item.petkind);
	}
	
}

void show(Tree* pets)
{
	Traverse(pets, ShowItem);
}

char* s_gets(char* ch, int len)
{
	char* ret_val;
	ret_val = fgets(ch, len, stdin);
	char* find;
	if (ret_val)
	{
		find = strchr(ch, '\n');
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
}

void ShowItem(Item* item)
{
	printf("%s %s	", item->petname, item->petkind);
}
