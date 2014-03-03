#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "graph.h"

int main()
{
	graph *g = malloc(sizeof(graph));
	init_graph(g, true);
	read_graph(g, true, "/home/tom/algos/graph_input.txt");
	bfs(g, 1);
	initialize_search(g);
	dfs(g, 1);
	return 0;
}

