#ifndef BFS_H
#define BFS_H

#include <stdio.h>
#include <stdlib.h>

#define QUEUESIZE 100

typedef struct queue
{
    int items[QUEUESIZE];
    int front;
    int rear;
} Queue;

Queue *create_queue();
void enqueue(Queue *q, int);
int dequeue(Queue *q);
void display(Queue *q);
int is_empty(Queue *q);
int front(Queue *q);

typedef struct node
{
    int vertex;
    struct node *next;
} Node;

Node *create_node(int);

typedef struct graph
{
    int num_vertices;
    Node **adj_lists;
    int *visited;
} Graph;

Graph *create_graph(int vertices);
void join(Graph *graph, int src, int dest);
void bfs(Graph *graph, int start_vert);

#endif