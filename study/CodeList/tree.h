#include <stdio.h>
#include <stdbool.h>
#define SLEN 20
#define SIZE 10

typedef struct item {
	char petname[SLEN];
	char petkind[SLEN];
} Item;

typedef struct trnode {
	Item item;
	struct trnode* left;
	struct trnode* right;
} Trnode;

typedef struct tree {
	Trnode* root;
	int size;
} Tree;

void InitTree(Tree* tp);

bool TreeIsEmpty(const Tree* tp);

int TreeItemCount(const Tree* tp);

bool TreeIsFull(const Tree* tp);

bool AddItem(Item item, Tree* tp);

bool InTree(const Item* item, const Tree* tp);

bool DelItem(const Item* item, Tree* tp);

void Traverse(const Tree* tp, void (*pfun)(Item item));

void DelAll(Tree* tp);