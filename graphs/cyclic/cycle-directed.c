#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

typedef struct graph
{
    int num_vertices;
    bool *visited;
    Node **adj_list;
} Graph;

Graph *create_graph(int);
Node *create_node(int v);
void join(Graph *, int, int);

Node *create_node(int v)
{
    Node *newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *create_graph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = vertices;

    graph->adj_list = malloc(vertices * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++)
    {
        graph->adj_list[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void join(Graph *graph, int src, int dest)
{
    struct node *newNode = create_node(dest);
    newNode->next = graph->adj_list[src]; //    2 -> 1 -> NULL
    graph->adj_list[src] = newNode;

    newNode = create_node(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newNode;
}

bool util(Graph *g, int node, int parent)
{
    g->visited[node] = true;
 
    for (Node* n = g->adj_list[node]; n != NULL; n=g->adj_list[node]->next) {
 
        if (!g->visited[n->vertex]) {
            if (util(g, n->vertex, node))
                return true;
        }
        else if (n->vertex != parent)
            return true;
    }
    return false;
}

bool is_cyclic(Graph *g)
{
    for (int i = 0; i < g->num_vertices; i++)
    {
        if (!g->visited[i])
            if (util(g, i, -1))
                return true;
    }
    return false;
}

int main()
{
    Graph *g = create_graph(4);
    join(g, 0, 1);                      // 0        2-> 1->NULL
    // join(g, 0, 2);                     //  1        2 -> NULL
    // join(g, 1, 2);                     //  2        3->0->NULL
    // join(g, 2, 0);                     // |true|false|true|false|
    // join(g, 2, 3);
    // join(g, 3, 3);

    if (is_cyclic(g))
        printf("Graph has a cycle.\n");
    else
        printf("Graph doesn't have cycle.\n");

    Graph* g1 = create_graph(3);
    join(g, 0, 1);
    join(g, 1, 2);

    if (is_cyclic(g1))
        printf("Graph has a cycle.\n");
    else
        printf("Graph doesn't have cycle.\n");

    return 0;
}
