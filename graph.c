#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "graph.h"
#include "queue.h"

/*bool bipartite;*/
/*bool processed[MAXV +1];*/
/*bool discovered[MAXV +1];*/
/*int parent[MAXV +1];*/
/*int color[MAXV + 1];*/
int time = 0;
int entry_time[MAXV + 1];
int exit_time[MAXV + 1];

void init_graph(graph *g, bool directed)
{
	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;

	int i;
	/* indexing the array of edges and degree starting at 1 so we can have edge 1, 2, 3, etc */
	for(i = 1; i <= MAXV; i++) {
		g->edges[i] = NULL;
		g->degree[i] = 0;
	}
}

void read_graph(graph *g, bool directed, const char *filename)
{
	int i;
	int number_of_edges;
	int x, y; /* vertices in edge (x, y) */
	FILE *f = fopen(filename, "r");	
	init_graph(g, directed);
	fscanf(f, "%d %d\n", &g->nvertices, &number_of_edges);
	printf("Constructing graph with %d vertices and %d edges\n", 
			g->nvertices, number_of_edges);

	/*for(i = 0; i < number_of_edges; i++) {*/
		/*scanf("%d %d", &x, &y);*/
		/*insert_edge(g, x, y, directed);*/
	/*}*/
	while(!feof(f)) {
		fscanf(f, "%d %d\n", &x, &y);
		insert_edge(g, x, y, directed);
	}
	fclose(f);
}

void insert_edge(graph *g, int x, int y, bool directed)
{
	edgenode *p = (edgenode *) malloc(sizeof(edgenode));
	p->y = y;
	p->weight = NULL;
	p->next = g->edges[x]; /* points to rest of adj list for x */

	g->edges[x] = p;  /*effectively inserting at the front of the list */	
	g->degree[x] = g->degree[x] + 1;
	
	if (directed == false) {
			insert_edge(g, y, x, true); /* Insert an edge (y, x)
						       for an undirected graph
						    */
	}
	else
		g->nedges = g->nedges + 1;
}

void print_graph(graph *g)
{
	int i;
	edgenode *v;

	for(i = 1; i <=g->nvertices; i++) {
		printf("%d: ", i);
		v = g->edges[i];
		while(v != NULL) {
			printf(" %d->", v->y);
			v = v->next;
		}
	printf("\n");
	}
}

void initialize_search(graph *g)
{
	int i;
	for(i = 1; i <=g->nvertices; i++) {
		processed[i] = discovered[i] = false;
		parent[i] = -1;
	}
}

bool finished(graph *g, int vertices)
{
	int i;
	bool fin = true;
	for(i = 1; i <= g->nvertices; i++) {
		if (processed[i] == false) {
			fin = false;
		}
	}
	return fin;
}

void dfs(graph *g, int vertex)
{
	edgenode *p;
	int y;

	if (finished(g, g->nvertices)) 
		return;

	discovered[vertex] = true;
	time = time + 1;
	entry_time[vertex] = time;

	process_vertex_early(vertex);

	p = g->edges[vertex];
	while (p != NULL) {
		y = p->y;
		if (discovered[y] == false) {
			parent[y] = vertex;
			process_edge(vertex, y);
			dfs(g, y);
		} else if ((!processed[y]) || (g->directed)) {
			process_edge(vertex, y);
		}
		if (finished(g, g->nvertices))
			return;
		p = p->next;
	}

	process_vertex_late(vertex);
	time = time + 1;
	exit_time[vertex] = time;
	processed[vertex] = true;
}

void bfs(graph *g, int start)
{
	queue *q = (queue *) malloc(sizeof(queue));
	int current_vertex;
	int next_vertex;
	edgenode *p;
	
	init(q);
	enqueue(q, start);
	discovered[start] = true;

	while(!empty(q)) {
		current_vertex = dequeue(q);
		process_vertex_early(current_vertex);
		processed[current_vertex] = true;
		p = g->edges[current_vertex];
		while (p != NULL) {
			next_vertex = p->y;
			if ((processed[next_vertex] == false) || g->directed) {
				process_edge(current_vertex, next_vertex);
			}
			if (discovered[next_vertex] == false) {
				enqueue(q, next_vertex);
				discovered[next_vertex] = true;
				parent[next_vertex] = current_vertex;
			}
			p = p->next;
		}
		process_vertex_late(current_vertex);
	}
}

void process_vertex_late(int v)
{
	printf("done processing node %d\n", v);
}

void process_vertex_early(int v)
{
	printf("start process node %d\n", v);
}

void process_edge(int x, int y) {
	printf("processed edge from %d -> %d\n", x, y);
}

void process_edge_twocolor(int x, int y)
{
	if (color[x] == color[y]) {
		bipartite = false;
		printf("Warning: not bipartite due to (%d, %d)\n", x, y);
	}
	color[y] = complement(color[x]);
}

void find_path(int start, int end, int parents[])
{
	if((start == end) || (end == -1)) {
		printf("\n%d", start);
	} else {
		find_path(start, parents[end], parents);
		printf(" %d", end);
	}
}

void connected_components(graph *g)
{
	int c, i;
	initialize_search(g);
	c = 0;
	for (i = 1; i <= g->nvertices; i++) {
		if(discovered[i] == false) {
			c = c + 1;
			printf("component %d:", c);
			bfs(g, i);
			printf("\n");
		}
	}
}

void twocolor(graph *g)
{
	int i;
	for (i = 1; i <=g->nvertices; i++) {
		color[i] = UNCOLORED;
	}

	initialize_search(g);
	bipartite = true;

	for(i = 1; i <= g->nvertices; i++) {
		if (discovered[i] == false) {
			color[i] = WHITE;
			bfs(g, i);
		}
	}
}

int complement(int color)
{
	if (color == WHITE) return BLACK;
	if (color == BLACK) return WHITE;
	return UNCOLORED;
}
