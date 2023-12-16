#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

typedef struct pair {
	Trnode* parent;
	Trnode* child;
} Pair;

static void AddNode(const Trnode* pnew, Trnode* root);
static Trnode* MakeNode(const Item* item);
static Pair SeekItem(const Item* item, const Trnode* root);
static bool ToLeft(const Item* pi1, const Item* pi2);
static bool ToRight(const Item* pi1, const Item* pi2);
static void DelNode(Trnode** ptr);
static void DelAllNode(Trnode* root);
static InOrder(const Trnode* root, void (*pfun)(Item item));

void InitTree(Tree* tp)
{
	tp->root = NULL;
	tp->size = 0;
}

bool TreeIsEmpty(const Tree* tp)
{
	return tp->size == 0;
}

int TreeItemCount(const Tree* tp)
{
	return tp->size;
}

bool TreeIsFull(const Tree* tp)
{
	return tp->size == SIZE;
}

bool AddItem(Item item, Tree* tp)
{
	Trnode* pnew;

	if (TreeIsFull(tp))
	{
		printf("The Tree is Full, no memory to add Item\n");
		return false;
	}

	if (SeekItem(&item, tp->root).child != NULL)
	{
		printf("The add Item is repeated\n");
		return false;
	}
	pnew = MakeNode(&item);
	if (pnew == NULL)
	{
		return false;
	}

	
	if (TreeIsEmpty(tp))
	{
		tp->root = pnew;
	}
	else
	{
		AddNode(pnew, tp->root);
	}
	tp->size++;
	return true;
}

bool InTree(const Item* item, const Tree* tp)
{
	if (SeekItem(item, tp->root).child == NULL)
	{
		printf("Connot find %s %s\n", item->petname, item->petkind);
	}
	else
	{
		printf("%s %s\n", item->petname, item->petkind);
	}
}

bool DelItem(const Item* item, Tree* tp)
{
	Pair look;
	look = SeekItem(item, tp->root);
	
	if (look.child == NULL)
	{
		printf("Connot find %s %s\n", item->petname, item->petkind);
		return false;
	}
	if (look.parent == NULL)
	{
		DelNode(&tp->root);
		tp->size--;
		return true;
	}
	DelNode(&look.child);
	tp->size--;
	return true;
}

void Traverse(const Tree* tp, void (*pfun)(Item item))
{
	if (tp->root != NULL)
	{
		InOrder(tp->root, pfun);
	}
	else
	{
		printf("The tree is Empty\n");
	}
	printf("\n");
}

static InOrder(const Trnode* root, void (*pfun)(Item item))
{
	if (root != NULL)
	{
		InOrder(root->left, pfun);
		pfun(root->item);
		InOrder(root->right, pfun);
	}
}

void DelAll(Tree* tp)
{
	DelAllNode(tp);
	tp->root = NULL;
	tp->size = 0;
}


static void DelAllNode(Trnode* root)
{
	Trnode* rnode;
	if (root != NULL)
	{
		rnode = root->right;
		DelAllNode(root->left);
		free(root);
		DelAllNode(rnode);
	}
	
}

static void DelNode(Trnode** ptr)
{
	Trnode* temp;

	if ((*ptr)->left == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->right;
		free(temp);
	}
	else if ((*ptr)->right == NULL)
	{
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
	else
	{
		
		temp = (*ptr)->left;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		temp->right = (*ptr)->right;
		temp = *ptr;
		*ptr = (*ptr)->left;
		free(temp);
	}
}

static Pair SeekItem(const Item* item, const Trnode* root)
{

	Pair look;
	look.parent = NULL;
	look.child = root;

	if (look.child == NULL)
	{
		return look;
	}
	while (look.child != NULL)
	{
		if (ToLeft(item, &look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->left;
		}
		else if (ToRight(item, &look.child->item))
		{
			look.parent = look.child;
			look.child = look.child->right;

		}
		else
		{
			break;
		}
	}
	return look;
}

static Trnode* MakeNode(const Item* item)
{
	Trnode* pnew;
	pnew = (Trnode*)malloc(sizeof(Trnode));
	pnew->item = *item;
	pnew->left = NULL;
	pnew->right = NULL;
	return pnew;
}

static void AddNode(const Trnode* pnew, Trnode* root)
{
	if (ToLeft(&pnew->item, &root->item))
	{
		if (root->left == NULL)
		{
			root->left = pnew;
		}
		else
		{
			AddNode(pnew, root->left);
		}
	}
	else if(ToRight(&pnew->item, &root->item))
	{
		if (root->right == NULL)
		{
			root->right = pnew;
		}
		else
		{
			AddNode(pnew, root->right);
		}
	}
	else
	{
		printf("add fialed\n");
	}
}

static bool ToLeft(const Item* pi1, const Item* pi2)
{
	int cmp1;

	if ((cmp1 = strcmp(pi1->petname, pi2->petname)) < 0)
	{
		return true;
	}
	else if (cmp1 == 0 && strcmp(pi1->petkind, pi2->petkind) < 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

static bool ToRight(const Item* pi1, const Item* pi2)
{
	int cmp1;

	if ((cmp1 = strcmp(pi1->petname, pi2->petname)) > 0)
	{
		return true;
	}
	else if (cmp1 == 0 && strcmp(pi1->petkind, pi2->petkind) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}