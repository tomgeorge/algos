#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

void init(stack *s)
{
	s->empty = true;
	s->size = 0;
	s->top = 0;
}

bool empty(stack *s)
{
	return s->size == 0;
}

bool full(stack *s)
{
	return s->size == STACK_SIZE;
}

int pop(stack *s)
{
	if(!empty(s)) {
		struct node n = s->stack[s->top--];
		int x = n->item;
		s->size--;
		return x;
	}
	return -1;
}

void push(stack *s, int x)
{
	struct node *n;
	if(!full(s)) {
		n = (struct node *)malloc(sizeof(struct node));
		n->item = x;
		s->stack[++(s->top)] = n;
		s->size++;
	}
}

int peek(stack *s)
{
	return s->stack[top]->item;
}

void print_stack(stack *s)
{
	int i;
	for(i = 0; i < s->size; i++) {
		printf("%d \n", (s->stack[i])->item);
	}
	printf("\n");
}
