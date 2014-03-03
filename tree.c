#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
	int element;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
} tree;

void traverse(tree *t)
{
	if (t == NULL) {
		return;
	} else {
		traverse(t->left);
		printf("t->element %c\n", t->element);
		traverse(t->right);
	}
}

int main()
{
	tree *t = (tree *) malloc(sizeof(tree));
	tree *l = (tree *) malloc(sizeof(tree));
	tree *r = (tree *) malloc(sizeof(tree));
	tree *x =  (tree *) malloc(sizeof(tree));
	t->element = 'A';
	l->element = 'B';
	r->element = 'C';
	x->element = 'X';
	x->left = NULL;
	x->right = NULL;
	x->parent = r;
	t->parent=NULL;
	l->parent=t;
	r->parent=t;
	t->left = l;
	l->left = NULL;
	r->left = NULL;
	t->right = r;
	r->right = x;
       	l->right = NULL;
	traverse(t);
}	
