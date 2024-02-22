#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "binary_tree.h"

typedef struct Queue
{
    node* n;
    struct Queue *next;
} Queue;

extern Queue *head;
extern Queue *tail;

void enqueue(Queue **, node*);
node* dequeue(Queue **);
bool isEmpty(Queue* head, Queue* tail);

#endif
