#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Queue{
  int data;
  struct Queue *next;
}Queue;

Queue *head = NULL;
Queue *tail = NULL;

void enqueue(Queue**, int);
int dequeue(Queue**);
void menu();

#endif
