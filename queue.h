#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

const int MAX = 4;
int head = -1;
int tail = -1;

void enqueue(int [], int);
int dequeue(int[]);
void menu();

#endif
