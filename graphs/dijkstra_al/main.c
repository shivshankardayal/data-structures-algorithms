#include "dijkstra_adj_list.h"

int main()
{
    int n = 7;
    Graph *g = create_graph(7);
    int dist[n], prev[n];
    int start = 0;

    join(g, 0, 1, 3);
    join(g, 0, 2, 6);
    join(g, 1, 0, 3);
    join(g, 1, 2, 2);
    join(g, 1, 3, 1);
    join(g, 2, 1, 6);
    join(g, 2, 1, 2);
    join(g, 2, 3, 1);
    join(g, 2, 4, 4);

    join(g, 2, 5, 2);
    join(g, 3, 1, 1);
    join(g, 3, 2, 1);
    join(g, 3, 4, 2);
    join(g, 3, 6, 4);
    join(g, 4, 2, 4);
    join(g, 4, 3, 2);
    join(g, 4, 5, 2);
    join(g, 4, 6, 1);
    join(g, 5, 2, 2);
    join(g, 5, 4, 2);
    join(g, 5, 6, 1);
    join(g, 6, 3, 4);
    join(g, 6, 4, 1);
    join(g, 6, 5, 1);

    dijkstra(g, dist, prev, start);

    for (int i = 0; i < n; i++)
        if (i != start)
            printf("%d to %d, Cost: %d Previous: %d\n", start, i, dist[i], prev[i]);

    return 0;
}