#include <stdio.h>
#include <stdbool.h>

#define MAXNODES 100

typedef struct vertex {
    char name;
} Vertex;

typedef struct edge {
    bool adj;
} Edge;

typedef struct graph {
    Vertex vertices[MAXNODES];
    Edge edges[MAXNODES][MAXNODES]; // this is called the adjacency matrix
} Graph;

void join(Graph* g, unsigned int vertex1, unsigned int vertex2) {
  (*g).edges[vertex1][vertex2].adj = true;
}

void rem(Graph* g, unsigned int vertex1, unsigned int vertex2) {
  (*g).edges[vertex1][vertex2].adj = false;
}

bool adjacent(Graph* g, unsigned int vertex1, unsigned int vertex2) {
  return ((*g).edges[vertex1][vertex2].adj == true) ? true: false;
}


// Transitive Closure
/* Assume that a graph is completely described by its adjacency matrix i.e.
   no data is associated with nodes and graph is not weighted. Consider the
   expression edges[i][k].adj && edges[j][k].adj, which is true only if both
   the sides of && is true, which implies that there is an edge from vertex
   i to vertex k and another arc from vertex j to vertex k i.e. there is a path
   of length 2 from i to j passing through k.

   Now consider (edges[i][0].adj && edges[0][j].adj) || (edges[i][1].adj && edges[1][j].adj)
   || ... || (edges[i][MAXNODES - 1].adj && edges[MAXNODES - 1][j].adj)

   This is true only if there is a path between vertices i and j through
   vertex 0 or vertex 1 or ... throgh node MAXNODES - 1. Effectively we are
   saying that there is some path of length 2 from node i to j. We can denote
   such an expression by adj2[i][j]. As we know matrix multiplication we realize
   that adj2 is product of adj(edges) with itself, with multiplication replaced
   by conjunction(&&) and addition replaced by disjunction(||). adj2 is said to
   be boolean product of adj with itself.

   Consider the graph shown:

    | A B C D E           | A B C D E
   ------------          ------------
   A| 0 0 1 1 0          A| 0 0 0 1 1
   B| 0 0 1 0 0          B| 0 0 0 1 1
   C| 0 0 0 1 1          C| 0 0 0 1 1
   D| 0 0 0 0 1          D| 0 0 0 1 0
   E| 0 0 0 1 0          E| 0 0 0 0 1
        adj                  adj2

    | A B C D E           | A B C D E
   ------------          ------------
   A| 0 0 0 1 1          A| 0 0 0 1 1
   B| 0 0 0 1 1          B| 0 0 0 1 1
   C| 0 0 0 1 1          C| 0 0 0 1 1
   D| 0 0 0 0 1          D| 0 0 0 1 0
   E| 0 0 0 1 0          E| 0 0 0 0 1
        adj3                 adj4

    | A B C D E
   ------------
   A| 0 0 1 1 1
   B| 0 0 1 1 1
   C| 0 0 0 1 1
   D| 0 0 0 1 1
   E| 0 0 0 1 1
   adj || adj2 || adj3

   The matrix path of often called transitive closure of the matrix adj.
*/

void transclose(Edge edges[][MAXNODES], Edge path[][MAXNODES]) {
	int newprod[MAXNODES][MAXNODES], adjprod[MAXNODES][MAXNODES];

	for(int i = 0; i < MAXNODES; ++i) {
		for(int j = 0; j < MAXNODES; ++j) {
			adjprod[i][j].adj = path[i][j].adj = edges[i][j].adj;
		}
	}

	for(int i = 1; i < MAXNODES; ++i) {
		// i represents the number of timess adj has been multiplies
		// with itself to obtain adjprod. At this point path
		// represents all paths of length i or less
		prod(adjprod, edges, newprod);
		for(int j = 0; j < MAXNODES; ++j) {
			for(int k = 0; k < MAXNODES; ++k) {
				path[j][k].adj = path[j][k].adj || newprod[j][k].adj;
			}
		}
		for(int j = 0; j < MAXNODES; ++j) {
			for(int k = 0; k < MAXNODES; ++k) {
				adjprod[j][k].adj = newprod[j][k].adj;
			}
		}
	}
}

void prod(Edge a[][MAXNODES], Edge b[][MAXNODES], Edge c[][MAXNODES]) {
	for(int i = 0; i < MAXNODES; ++i) {
		for(int j = 0; j < MAXNODES; ++i) {
			bool val = false;
			for(int k = 0; k < MAXNODES; ++k) {
				val = val || (a[i][k].adj && b[k][j].adj);
				c[i][j] = val;
			}
		}
	}
}


// Complexity of transclose is O(n^4)

void warshall(Edge edges[][MAXNODES], Edge path[][MAXNODES]) {
	for(int i = 0; i < MAXNODES; ++i) {
		for(int j = 0; j < MAXNODES; ++j) {
			path[i][j].edge = edges[i][j].edge;
		}
	}

	for(int k = 0; k < MAXNODES; ++k) {
		for(int i = 0; i < MAXNODES; ++i) {
			if(path[i][k].edge) {
				for(int j = 0; j < MAXNODES; ++j) {
					path[i][j].edge = path[i][j].edge || path[k][j].edge;
				}
			}
		}
	}
}

//This reduces the complexity to O(n^3)
