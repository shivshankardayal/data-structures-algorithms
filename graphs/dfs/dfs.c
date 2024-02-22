#include "dfs.h"

void dfs(Graph *graph, int vertex)
{
    Node *adjList = graph->adj_list[vertex];
    Node *temp = adjList;

    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL)
    {
        int connectedVertex = temp->vertex;
        if (graph->visited[connectedVertex] == 0)
        {
            dfs(graph, connectedVertex);
        }
        temp = temp->next;
    }
}

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

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adj_list[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

void join(Graph *graph, int src, int dest)
{
    struct node *newNode = create_node(dest);
    newNode->next = graph->adj_list[src];
    graph->adj_list[src] = newNode;

    newNode = create_node(src);
    newNode->next = graph->adj_list[dest];
    graph->adj_list[dest] = newNode;
}

void print(Graph *graph)
{
    int v;
    for (v = 0; v < graph->num_vertices; v++)
    {
        struct node *temp = graph->adj_list[v];
        printf("\n Adjacency list of vertex %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}