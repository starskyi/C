#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

static void CopyToNode(Item item, Node* pnew);
static void CopyToItem(Item* item, Node* pdel);

void InitQueue(Queue* pq)
{
	pq->front = pq->rear = NULL;
	pq->items = 0;

}

bool QueueIsEmpty(const Queue* pq)
{
	return pq->items == 0;
}

bool QueueIsFull(const Queue* pq)
{
	return pq->items == MAXSIZE;
}

bool EnQueue(Item item, Queue* pq)
{
	Node* pnew;

	if (QueueIsFull(pq))
	{
		printf("%d\n", QueueIsFull);
		printf("%d\n", pq->items);
		return false;
	}
	pnew = (Node*)malloc(sizeof(Node));

	if (pnew == NULL)
	{
		fprintf(stderr, "Unable to allocate memory");
		exit(1);
	}

	CopyToNode(item, pnew);
	
	pnew->next = NULL;

	if (QueueIsEmpty(pq))
	{
		pq->front = pq->rear =  pnew;
		pq->items++;
	}
	else
	{
		pq->rear->next = pnew;
		pq->rear = pnew;
		pq->items++;
		
	}
	return true;
}

bool DelQueue(Item* item, Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		fprintf(stderr, "No Item to remove");
		return false;
	}

	Node* temp;

	temp = pq->front;
	CopyToItem(item, temp);
	pq->front = pq->front->next;
	free(temp);
	pq->items--;

	if (pq->items == 0)
	{
		pq->rear = NULL;
	}
	return true;
}

int QueueItemCount(const Queue* pq)
{
	return pq->items;
}

void EmptyQueue(Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		fprintf(stderr, "The Queue has no Item");
		return;
	}
	while (!QueueIsEmpty(pq))
	{
		Item item;
		DelQueue(&item, pq);
	}
}

void ShowQueue(const Queue* pq)
{
	if (QueueIsEmpty(pq))
	{
		printf("No item to show \n");
		return;
	}

	Node* temp;
	temp = pq->front;
	while (temp)
	{
		printf("%d ", temp->item);
		temp = temp->next;
	}
	printf("\n");
}

static void CopyToNode(Item item, Node* pnew)
{
	pnew->item = item;
}

static void CopyToItem(Item* item, Node* pdel)
{
	*item = pdel->item;
}

