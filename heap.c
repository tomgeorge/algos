#include <stdio.h>
#include <stdlib.h>
#define HEAP_SIZE 100
/* Min heap Implemented as a priority queue */
typedef struct priority_queue {
	int q[HEAP_SIZE+1]; /* Array holding elements */
	int n;  	      /* Current size of priority queue */
} priority_queue;

void bubble_up(priority_queue *q, int p);
void pq_swap(priority_queue *q, int p1, int p2);
int extract_min(priority_queue *q);
void heapify(priority_queue *q, int p); /* AKA bubble_down */
void heapsort(int s[], int n);
void make_heap(priority_queue *q, int s[], int n);
void pq_init(priority_queue *q);

void print(priority_queue *q, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", q->q[i]);
	printf("\n");
}

int extract_min(priority_queue *q)
{
	int min = -1;
	if (q->n < 0) 
		printf("empty heap\n");
	else {
		min = q->q[0];
		q->q[0] = q->q[q->n];
		q->n = q->n - 1;
		heapify(q, 0);
	}
	return min;
}

void heapify(priority_queue *q, int p)
{
	int child_index;
	int i;
	int min_index;

	child_index = pq_young_child(p);
	min_index = p;
//	printf("child index %d min_index %d element at root %d element at child index %d element at min index %d\n", 
//			child_index, min_index, q->q[p], q->q[child_index], q->q[min_index]);

	for(i = 0; i <= 1; i++) {
		if(child_index + i <= q->n) {
			if (q->q[min_index] > q->q[child_index + i]) {
				min_index = child_index + i;
			}
		}
	}
	if(min_index != p) {
		pq_swap(q, p, min_index);
		heapify(q, min_index);
	}
}

void heapsort(int s[], int n)
{
	int i;
	priority_queue *q = malloc(sizeof(priority_queue));
	pq_init(q);
	make_heap(q, s, n);
	int j;
	for(i = 0; i < n; i++) {
		s[i] = extract_min(q);
	}
}


int pq_parent(int n)  /* N is a position. Parent resides at floor(n/2) */
{
	if (n == 0)
		return -1;
	else
		return ((int) n/2);
}

int pq_young_child(int n) /* N is a position.  Younger child resides at position 2n */ 
{
	if(n == 0)
		return 1;
	else
		return 2*n;
}

int pq_old_child(int n) /* N is a position.  Older child resides at position 2n + 1 */
{
	return (2 * n) + 1;
}

void pq_insert(priority_queue *q, int x) /* x is element to insert */
{
	// printf("q->n %d\n", q->n);
	if (q-> n >= HEAP_SIZE)
		printf("Overflow\n"); 	/* At root, no parent */
	else {
		q->n = q->n + 1; 	/* Increase heap size */
		q->q[q->n] = x; 	/* Insert element at leftmost position */
		bubble_up(q, q->n); 	/* Bubble up */
	}
}

void bubble_up(priority_queue *q, int p) /* P is a position */
{
	if (pq_parent(p) == -1)
		return; 	/* At root, no parent */
	if (q->q[pq_parent(p)] > q->q[p]) { /* If element at parent position of p is greater than element at position p */
	  //       printf("pq_parent %d\n", pq_parent(p));	
		pq_swap(q, p, pq_parent(p)); 	/* Swap elements at position p and pq_parent(p) */
		bubble_up(q, pq_parent(p));
	}
}

void pq_swap(priority_queue *q, int p1, int p2)
{
	int tmp = q->q[p1];
	q->q[p1] = q->q[p2];
	q->q[p2] = tmp;
}

void pq_init(priority_queue *q)
{
	q->n = -1;
}

void make_heap(priority_queue *q, int s[], int n)
{
	int i;
	for(i = 0; i < n; i++) {
		pq_insert(q, s[i]);
	}
}

void print_pq(priority_queue *q, int n)
{
	int i;
	for(i = 0; i < n; i++)
		printf("q[%d]=%d\n", i, q->q[i]);
	printf("\n");
}

void printa(int a[], int n)
{
	int i = 0; 
	for(i; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(int argc, char **argv)
{
	int items[] = {1918, 2001, 1941, 1963, 1945, 1865, 1804/*, 1783, 1776, 1492*/};
	priority_queue *queue = malloc(sizeof(priority_queue));
	pq_init(queue);
	make_heap(queue, items, 7);
//	make_heap(queue, items, 3);
//	print_pq(queue, 10);
//	printf("extract_min %d\n", extract_min(queue));
//	print_pq(queue, 10);
//	printf("extract_min %d\n", extract_min(queue));
//	print_pq(queue, 10);
//	printf("extract_min %d\n", extract_min(queue));
//	print_pq(queue, 10); 
 	int i;
/*	for(i = 0; i < 10; i++)
		printf("%d ", queue->q[i]);
	printf("\n"); */

	printf("before\n");
	printa(items, 7);
	heapsort(items, 7);
	printf("after\n");	
	printa(items, 7);
}






