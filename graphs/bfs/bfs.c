#include "bfs.h"

void bfs(Graph *graph, int start_vert)
{
    Queue *q = create_queue();

    graph->visited[start_vert] = 1;
    enqueue(q, start_vert);
    printf("Breadth-first traversal starting from vertex %d is:\n", start_vert);

    while (!is_empty(q))
    {
        printf("%d ", front(q));
        int current_vert = dequeue(q);

        Node *temp = graph->adj_lists[current_vert];
        while (temp)
        {
            int adj_vertex = temp->vertex;

            if (graph->visited[adj_vertex] == 0)
            {
                graph->visited[adj_vertex] = 1;
                enqueue(q, adj_vertex);
            }
            temp = temp->next;
        }
    }
}

Node *create_node(int v)
{
    Node *temp = malloc(sizeof(Node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

Graph *create_graph(int vertices)
{
    Graph *graph = malloc(sizeof(Graph));
    graph->num_vertices = vertices;

    graph->adj_lists = malloc(vertices * sizeof(Node *));
    graph->visited = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adj_lists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void join(Graph *graph, int src, int dest)
{
    Node *temp = create_node(dest);
    temp->next = graph->adj_lists[src];
    graph->adj_lists[src] = temp;

    // temp = create_node(src);
    // temp->next = graph->adj_lists[dest];
    // graph->adj_lists[dest] = temp;
}

Queue *create_queue()
{
    Queue *q = malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int is_empty(Queue *q)
{
    if (q->rear == -1)
        return 1;
    else
        return 0;
}

void enqueue(Queue *q, int value)
{
    if (q->rear == QUEUESIZE - 1)
        printf("\nQueue is Full!!");
    else
    {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue *q)
{
    int item;

	if (is_empty(q))
    {
        printf("Queue is empty");
        item = -1;
    }
    else
    {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear)
        {
            q->front = q->rear = -1;
        }
    }

    return item;
}

int front(Queue *q) { return q->items[q->front]; }
