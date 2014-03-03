#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"

int main(int argc, char **argv)
{
	stack *s = (stack *)malloc(sizeof(stack));
	init(s);
	printf("empty: %d\n", empty(s));
	push(s, 5);
	push(s, 6);
	push(s, 7);
	printf("peek: %d\n", peek(s));
	print_stack(s);
}
