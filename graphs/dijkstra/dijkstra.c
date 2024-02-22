#include "dijkstra.h"


// Finds the vertex with minimum
// distance, from the set of vertices not yet included
// in shortest path tree
int min_distance(int dist[], bool spt_set[])
{
 
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int v = 0; v < MAXNODES; v++)
        if (spt_set[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;
 
    return min_index;
}

void print_graph(int dist[])
{
    for (int i = 0; i < MAXNODES; i++)
        printf("%d %d\n", i,dist[i]);
}

void dijkstra(int weight[][MAXNODES], int source)
{
    int min_dist[MAXNODES];
    bool spt_set[MAXNODES];

    for (int i = 0; i < MAXNODES; i++) {
        min_dist[i] = INT_MAX;
        spt_set[i] = false;
    }

    min_dist[source] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < MAXNODES - 1; count++)
    {
        int u = min_distance(min_dist, spt_set);

        spt_set[u] = true;

        // Update dist value of the adjacent vertices of the
        // picked vertex.
        for (int v = 0; v < MAXNODES; v++)

            // Updates dist[v] only if is not in spt_set,
            // an edge exists from u to v, and total
            // weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!spt_set[v] && weight[u][v] && min_dist[u] != INT_MAX && min_dist[u] + weight[u][v] < min_dist[v])
                min_dist[v] = min_dist[u] + weight[u][v];
    }

    print_graph(min_dist);
}
