#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init(queue *q)
{
	q->size = 0;
	q->head = NULL;
}

int empty(queue *q)
{
	return q->size == 0;
}

void enqueue(queue *q, int x)
{
	node *n = (node *)malloc(sizeof(node));
	n->item = x;
	n->next = NULL;

	if(empty(q)) {
		q->head = n;
		q->tail = n;
	}
	else {
		q->tail->next = n;
		q->tail = q->tail->next;
	}
	q->size++;
}

int dequeue(queue *q)
{
	if(!empty(q)) {
		int item = q->head->item;
		node *temp = q->head;
		q->head = q->head->next;
		free(temp);
		q->size--;
		return item;
	}
	return -1;
}

int peek(queue *q)
{
	if(!empty(q)) {
		return q->head->item;
	}
	else 
		return -1;
}
void print_q(queue *q)
{
	node *temp = q->head;
	for(temp; temp != NULL; temp = temp->next) {
		printf("%d ", temp->item);
	}
	printf("\n");
}

/*int main() {*/
	/*queue *q = malloc(sizeof(queue));*/
	/*init(q);*/
	/*enqueue(q, 2);*/
	/*enqueue(q, 3);*/
	/*enqueue(q, 4);*/
	/*enqueue(q, 1);*/
	/*print_q(q);*/
	/*dequeue(q);*/
	/*dequeue(q);*/
	/*print_q(q);*/
	/*dequeue(q);*/
	/*dequeue(q);*/
	/*print_q(q);*/
	/*dequeue(q);*/
	/*enqueue(q, 10);*/
	/*print_q(q);*/
	/*return 0;*/
/*}*/
