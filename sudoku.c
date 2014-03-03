#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DIMENSION 9
#define NCELLS DIMENSION * DIMENSION

void backtrack(int a[], int k, int input);

typedef struct point {
	int x; 
	int y;
} point;

typedef struct board {
	int m[DIMENSION + 1][DIMENSION + 1];
	int freecount;
	point move[NCELLS +1];
} board;

void construct_candidates(int a[], int k, board *board, int c[], int *ncandidates)
{
	int x, y;
	int i;
	bool possible[DIMENSION + 1];

	next_square(&x, &y, board);

	board->move[k].x = x;
	board->move[k].y = y;

	*ncandidates = 0;

	if ((x < 0) && (y < 0))
		return;

	possible_values(x, y, board, possible);
	for(i = 0; i <= DIMENSION; i++)
		if (possible[i] == true) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
}
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
