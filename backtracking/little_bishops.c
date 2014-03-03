#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
bool finished = false;

void backtrack(int solution_array[], int current_position, int dimension, int num_bishops);
int bishop_placement(int solution_array[], int current_position, int dimension, int num_bishops);
bool is_a_solution(int solution_array[], int current_position);
void process_solution(int solution_array[], int current_position);
void construct_candidates(int solution_array[], int current_position, int candidates[], int *num_candidates,
		int dimension, int num_bishops);

bool is_a_solution(int solution_array[], int current_position)
{
}

void process_solution(int solution_array[], int current_position)
{
}

void construct_candidates(int solution_array[], int current_position, int candidates[], int *num_candidates, int dimension, int num_bishops)
{
	bool legal_move;
	int i, j;
	*num_candidates = 0;
}

void backtrack(int solution_array[], int current_position, int dimension, int num_bishops)
{
	int i, j;
	int candidates[dimension * dimension];
	int num_candidates;
	
	if (is_a_solution(solution_array, current_position)) {
		process_solution(solution_array, current_position);
	}
	else {
		current_position = current_position + 1;
		construct_candidates(solution_array, current_position, candidates, &num_candidates, dimension, num_bishops);
		for(i = 0; i < num_candidates; i ++) {
				solution_array[current_position] = candidates[i];
				backtrack(solution_array, current_position, dimension, num_bishops);
				if (finished)
					return;
		}
	}
}


int bishop_placement(int solution_array[], int current_position, int dimension, int num_bishops)
{
	backtrack(solution_array, current_position, num_bishops, dimension);
	return solution_array[0];
}


int main(int argc, char **argv)
{
	int dimension;
	int num_bishops;

	FILE *fp = fopen("bisop_input.txt", "r");
	while (!feof(fp)) {
		int a[9999];	
		fscanf(fp, "%d %d", &dimension, &num_bishops);
		if (dimension != 0 && num_bishops != 0) {
			bishop_placement(a, 0, dimension, num_bishops);
			printf(" %d %d\n", dimension, num_bishops);
		}
	}

	return 0;
}

