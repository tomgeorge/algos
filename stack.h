#ifndef STACK_H
#define STACK_H
#include <stdbool.h>
#define STACK_SIZE 500
typedef struct node{
	int item;
	struct node *next;
} node;
typedef struct stack{
	bool empty;
	int size;
	node stack[STACK_SIZE];	
	int top;
}stack;

void init(stack *s);
bool empty(stack *s);
bool full(stack *s);
void push(stack *s, int x);
int pop(stack *s);
int peek(stack *s);
void print_stack(stack *s);
#endif
