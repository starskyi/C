#include <stdio.h>
#include <stdlib.h>
#include "list.h"

static void CopyItemToNode(Item item,Node* pnode);

void InitializeList(List* plist)
{
	*plist = NULL;
}

bool ListIsEmpty(const List* plist)
{
	if (*plist == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool AddItem(Item item, List* list)
{
	Node* node;
	Node* scan = *list;
	node = (Node*)malloc(sizeof(Node));
	if (node == NULL)
		return false;
	CopyItemToNode(item, node);
	if (*list == NULL)
	{
		*list = node;
	}
	else
	{
		while (scan->next != NULL)
		{
			scan = scan->next;
		}
		scan->next = node;
	}

	node->next = NULL;
}

unsigned int ListItemCount(const List* list)
{
	unsigned int i = 1;
	Node* cur;
	if ((cur = *list) == NULL)
		return 0;
	while (cur->next != NULL)
	{
		i++;
		cur = cur->next;
	}
	return i;
}

bool ListIsFull(const List* list)
{
	Node* node;
	node = malloc(sizeof(Node));
	if (node)
	{
		free(node);
		return false;
	}
	return true;
}

void EmptyList(List* list)
{
	Node* cur = *list;
	Node* node;
	while (cur != NULL)
	{
		node = cur;
		cur = cur -> next;
		free(node);
	}
}

void Traverse(const List* list, void (*pfun)(Item* item))
{

	Node* node = *list;
	while (node != NULL)
	{
		pfun(&node->item);
		node = node->next;
	}
}

static void CopyItemToNode(Item item, Node* pnode)
{
	pnode->item = item;
}
