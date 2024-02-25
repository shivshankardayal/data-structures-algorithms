#include "dijkstra_adj_list.h"

Heap *create_heap(Heap *heap)
{
    heap = (Heap *)malloc(sizeof(Heap));
    heap->size = 1;
    heap->p = (int *)malloc(heap->size * sizeof(int));
    heap->count = 0;
    return heap;
}

void heap_down(Heap *heap, int index)
{
    if (index >= heap->count)
        return;

    int left = index * 2 + 1;
    int right = index * 2 + 2;
    int leftflag = 0, rightflag = 0;
    int minimum = *((heap->p) + index);

    if (left < heap->count && minimum > *((heap->p) + left))
    {
        minimum = *((heap->p) + left);
        leftflag = 1;
    }
    if (right < heap->count && minimum > *((heap->p) + right))
    {
        minimum = *((heap->p) + right);
        leftflag = 0;
        rightflag = 1;
    }
    if (leftflag)
    {
        *((heap->p) + left) = *((heap->p) + index);
        *((heap->p) + index) = minimum;
        heap_down(heap, left);
    }
    if (rightflag)
    {
        *((heap->p) + right) = *((heap->p) + index);
        *((heap->p) + index) = minimum;
        heap_down(heap, right);
    }
}

void heap_up(Heap *heap, int index)
{
    int parent = (index - 1) / 2;

    if (parent < 0)
        return;

    if (*((heap->p) + index) < *((heap->p) + parent))
    {
        int temp = *((heap->p) + index);
        *((heap->p) + index) = *((heap->p) + parent);
        *((heap->p) + parent) = temp;
        heap_up(heap, parent);
    }
}

void push(Heap *heap, int x)
{
    if (heap->count >= heap->size)
        return;

    *((heap->p) + heap->count) = x;
    heap->count++; // count 2 size 4       |3|10|||
                   //
    if (4 * heap->count >= 3 * heap->size)
    {
        heap->size *= 2;
        (heap->p) = (int *)realloc((heap->p), (heap->size) * sizeof(int));
    }
    heap_up(heap, heap->count - 1);
}

void pop(Heap *heap)
{
    if (heap->count == 0)
        return;

    heap->count--;

    int temp = *((heap->p) + heap->count);

    *((heap->p) + heap->count) = *(heap->p);
    *(heap->p) = temp;
    heap_down(heap, 0);

    if (4 * heap->count <= heap->size)
    {
        heap->size /= 2;
        (heap->p) = (int *)realloc((heap->p), (heap->size) * sizeof(int));
    }
}

int empty(Heap *heap)
{
    if (heap->count != 0)
        return 0;
    else
        return 1;
}

int top(Heap *heap)
{
    if (heap->count != 0)
        return *(heap->p);
    else
        return INT_MIN;
}

Graph *create_graph(int n)
{
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->num_vertices = n;
    g->adj_list = (Node **)malloc(sizeof(Node **) * g->num_vertices);

    for (int i = 0; i < g->num_vertices; i++)
    {
        g->adj_list[i] = NULL;
    }

    return g;
}

void join(Graph *g, int src, int dest, int cost)
{
    Node *node = (Node *)malloc(sizeof(node));

    node->cost = cost;
    node->dest = dest;
    node->next = g->adj_list[src];
    g->adj_list[src] = node;
}

void dijkstra(Graph *g, int *dist, int *prev, int start)
{
    for (int i = 0; i < g->num_vertices; i++)
    {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    dist[start] = 0;
    Heap *heap = NULL;
    heap = create_heap(heap);

    for (int i = 0; i < g->num_vertices; i++)
    {
        push(heap, i);
    }

    while (!empty(heap))
    {
        int i = top(heap);
        pop(heap);

        for (Node *n = g->adj_list[i]; n != NULL; n = n->next)
        {
            if ((dist[i] + (n->cost)) < dist[n->dest])
            { // relax (u,v)
                dist[n->dest] = (dist[i] + (n->cost));
                prev[n->dest] = i;
            }
        }
    }
}
