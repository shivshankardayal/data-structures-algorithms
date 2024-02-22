#include "dfs.h"

int main()
{
    Graph* graph = create_graph(5);
    join(graph, 0, 1);
    join(graph, 0, 2);
    join(graph, 1, 2);
    join(graph, 2, 3);
    join(graph, 2, 4);
    printf("DFS from 0 is:\n");
    dfs(graph, 2);
    printf("\n");

    return 0;
}