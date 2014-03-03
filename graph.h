#ifndef GRAPH_H
#define GRAPH_H
#include <stdbool.h>
#define MAXV 	1000 /* Maximum number of vertices */
enum color {WHITE, BLACK, UNCOLORED};
bool bipartite;
bool processed[MAXV +1];
bool discovered[MAXV +1];
int parent[MAXV +1];
int color[MAXV + 1];
typedef struct edgenode {
	int y; /* Node it is adjacent to (x, y)*/
	int weight; /*edge weight */
	struct edgenode *next; /*pointer to next edge in list */
} edgenode;


typedef struct graph{
	edgenode *edges[MAXV +1];  /*adjacency info */
	int degree[MAXV +1]; /* outdegree of each vertex */
	int nvertices; /*number of vertices in graph */
	int nedges; /*number of edges in graph */
	bool directed; /* directed? */
} graph;

void init_graph(graph *g, bool directed);
void read_graph(graph *g, bool directed, const char *filename);
void insert_edge(graph *g, int x, int y, bool directed);
void print_graph(graph *g);
void bfs(graph *g, int start);
void dfs(graph *g, int vertex);
void initialize_search (graph *g);
void process_vertex_late(int v);
void process_vertex_early(int v);
void process_edge(int x, int y);
void find_path(int start, int end, int parents[]);
void connected_components(graph *g);
void twocolor(graph *g);
int complement(int color);
bool finished(graph *g, int vertices);
#endif
