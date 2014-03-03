#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#define GIANT_ASS_NUMBER /*2000000*/ 10000
void quicksort(int s[], int low, int high);
int partition(int s[], int low, int high);
void mergesort(int s[], int low, int high);
int binary_search(int s[], int q, int low, int high);
void merge(int s[], int low, int middle, int high);
void swap(int *a, int *b);

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void quicksort(int s[], int low, int high)
{
	int p;
	if((high - low) > 0) {
		p = partition(s, low, high);
		quicksort(s, low, p-1);
		quicksort(s, p+1, high);
	}
}

int partition(int s[], int low, int high)
{
	int i, p, firsthigh;

	p = high;
	firsthigh = low;
	for(i = low; i < high; i++)
		if (s[i] < s[p]) {
			swap(&s[i], &s[firsthigh]);
			firsthigh++;
		}
	swap(&s[p], &s[firsthigh]);
	return firsthigh;
}

void mergesort(int s[], int low, int high)
{
	int i;
	int middle;
	if(low < high) {
		middle = (low + high)/2;
		/*printf("ms low %d middle %d high %d\n", low, middle, high);*/
		/*printf("left side\n");*/
		mergesort(s, low, middle);
		/*printf("right side\n");*/
		mergesort(s, middle + 1, high);
		merge(s, low, middle, high);
	}
}

void merge(int s[], int low, int middle, int high)
{
	/*printf("merge low %d middle %d high %d\n", low, middle, high);*/
	int i;
	queue *buffer1, *buffer2;
	buffer1 = malloc(sizeof(queue));
	buffer2 = malloc(sizeof(queue));
	init(buffer1);
	init(buffer2);

	for(i = low; i <= middle; i++) {
		enqueue(buffer1, s[i]);
	}
	for(i = middle+1; i <= high; i++) {
		enqueue(buffer2, s[i]);
	}
	/*printf("enqueued\n");*/
	i = low;
	while(!(empty(buffer1) || empty(buffer2))) {
		if(peek(buffer1) < peek(buffer2)) {
			s[i] = dequeue(buffer1);
			i++;
		}
		else {
			s[i] = dequeue(buffer2);
			i++;
		}
	}
	/*printf("added to array\n");*/
	while(!empty(buffer1)) {
		s[i] = dequeue(buffer1);
		i++;
	}
	while(!empty(buffer2)) {
		s[i] = dequeue(buffer2);
		i++;
	}
	/*printf("dequeue all queues\n");*/
}

int binary_search(int s[], int q, int low, int high)
{
	if (low < high) {
		int middle = (low + high) / 2;
		if (s[middle] == q)
			return middle;
		if ( q > s[middle] )
			return binary_search(s, q, middle + 1, high);
		if (q < s[middle])
			return binary_search(s, q, low, middle -1);
	}
	else return -10;
}


int main(int argc, char *argv[])
{
	int i;
	int items[] = {10, 20, 30, 40, 44, 67, 23, 102, 39, 21, 56};
	int items2[GIANT_ASS_NUMBER];
	int j;
	for(j = 0; j < GIANT_ASS_NUMBER; j++)
		items2[j] = random();

	printf("sorting big list\n");
	quicksort(items2, 0, GIANT_ASS_NUMBER);
	printf("done\n");
	
	for (i = 0; i < GIANT_ASS_NUMBER; i ++) {
		for(j = i + 0; j < i + 20; j++) {
			printf("%d ", items2[i]);
		}
		printf("\n");
	}

	/*printf("before\n");*/
	/*for(i = 0; i < 11; i++) {*/
		/*printf("%d ", items[i]);*/
	/*}*/
	/*printf("\n");*/
	/*quicksort(items, 0, 10);*/
	/*printf("after\n");*/
	/*for(i = 0; i < 11; i++) {*/
		/*printf("%d ", items[i]);*/
	/*}*/
	/*printf("\n");*/
	/*int query = 40;*/
	/*printf("search for %d: [%d]\n", query, binary_search(items, query, 0, 10));*/
}
