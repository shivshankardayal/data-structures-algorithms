#include "bfs.h"

int main()
{
    Graph* graph = create_graph(6);

    join(graph, 0, 1);
    join(graph, 0, 2);
    join(graph, 1, 2);
    join(graph, 1, 3);
    join(graph, 2, 4);
    join(graph, 3, 4);
    bfs(graph,0);

    return 0;
}
