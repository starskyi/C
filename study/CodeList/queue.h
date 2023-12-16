#include <stdio.h>
#include <stdbool.h>
#define MAXSIZE 10

typedef int Item;

typedef struct node {
	Item item;
	struct node * next;
} Node;

typedef struct queue {
	Node* front;
	Node* rear;
	int items;
} Queue;

void InitQueue(Queue* pq);

bool QueueIsEmpty(const Queue* pq);

bool QueueIsFull(const Queue* pq);

bool EnQueue(Item item, Queue* pq);

bool DelQueue(Item * item, Queue* pq);

int QueueItemCount(const Queue* pq);

void EmptyQueue(Queue* pq);

void ShowQueue(const Queue* pq);