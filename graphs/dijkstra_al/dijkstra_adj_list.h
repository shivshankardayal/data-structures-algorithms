#ifndef DIJKSTRA_ADJ_LIST_H
#define DIJKSTRA_ADJ_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int dest;
    int cost;
    struct node *next;
} Node;

typedef struct graph
{
    int num_vertices;
    Node **adj_list;
} Graph;

typedef struct min_heap
{
    int *p;
    int size;
    int count;
} Heap;

Heap *create_heap(Heap *heap);
void heap_down(Heap *heap, int index);
void heap_up(Heap *heap, int index);
void push(Heap *heap, int x);
void pop(Heap *heap);
int top(Heap *heap);
int empty(Heap *heap);
Graph *create_graph(int n);
void join(Graph *g, int src, int dest, int cost);
void dijkstra(Graph* g, int *dist, int *prev, int start);

#endif
