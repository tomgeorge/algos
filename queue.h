#ifndef QUEUE_H
#define QUEUE_H
typedef struct node{
	int item;
	struct node *next;
} node;
typedef struct queue{
	int size;
	node *head;
	node *tail;
}queue;

void init(queue *q);
int empty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
int peek(queue *q);
void print_q(queue *q);
#endif
