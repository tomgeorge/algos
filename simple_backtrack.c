#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool finished = false;
void backtrack(int a[], int k, int input);
bool is_a_solution(int a[], int k, int n);
void construct_candidates(int a[], int k, int n, int c[], int *ncandidates);
void process_solution_perms(int a[], int k);
void construct_candidates_perms(int a[], int k, int n, int c[], int *ncandidates);
void process_solution(int a[], int k);
void generate_subsets(int n);
void generate_permutations(int n);

void backtrack(int a[], int k, int input)
{
	int c[500];
	int ncandidates;
	int i;

	if (is_a_solution(a, k, input))
		process_solution_perms(a, k);
	else {
		k = k + 1;
		construct_candidates_perms(a, k, input, c, &ncandidates);
		for(i = 0; i < ncandidates; i++) {
			a[k] = c[i];
			// make_move(a, k, input);
			backtrack(a, k, input);
		// 	unmake_move(a, k, input);
			if (finished)
				return;
		}
	}
}

bool is_a_solution(int a[], int k, int n)
{
	return (k == n);
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	c[0] = true;
	c[1] = false;
	*ncandidates = 2;
}

void construct_candidates_perms(int a[], int k, int n, int c[], int *ncandidates)
{
	int i;
	bool in_perm[500];

	for(i = 1; i < n; i++)
		in_perm[i] = false;
	for(i = 0; i < k; i++)
		in_perm[ a[i] ] = true;

	*ncandidates = 0;
	for (i = 1; i <=n; i++) {
		if(in_perm[i] == false) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
	}
}


void process_solution(int a[], int k)
{
	int i;

	printf("{");
	for(i = 1; i <=k; i++)
		if(a[i] == true)
			printf(" %d", i);
	printf(" }\n");
}

void process_solution_perms(int a[], int k)
{
	int i;
	for(i = 1; i <=k; i++)
		printf(" %d", a[i]);
	printf("\n");
}

void generate_subsets(int n)
{
	int a[500];
	backtrack(a, 0, n);
}
void generate_permutations(int n) 
{
	int a[500];
	backtrack(a, 0, n);
}


int main(int argc, char **argv)
{
	generate_permutations(3);
}
