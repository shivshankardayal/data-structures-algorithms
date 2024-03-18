#ifndef DFS_H
#define DFS_H

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

Node *create_node(int v);

typedef struct graph
{
    int num_vertices;
    int *visited;
    Node **adj_list;
} Graph;

Graph *create_graph(int);
void join(Graph *, int, int);
void print(Graph *);

#endif