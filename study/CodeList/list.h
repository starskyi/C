#include <stdio.h>
#include <stdbool.h>
#define TSIZE 40

struct film {
	char title[TSIZE];
	int rating;
};

typedef struct film Item;

typedef struct node {
	Item item;
	struct node* next;
} Node;

typedef Node* List;

void InitializeList(List* plist);

bool ListIsEmpty(const List* plist);

bool AddItem(Item item, List* list);

unsigned int ListItemCount(const List* list);

bool ListIsFull(const List* list);

void EmptyList(List* list);

void Traverse(const List* list, void (*pfun)(Item *item));