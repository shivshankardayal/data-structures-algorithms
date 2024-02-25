#ifndef MINHEAP_H
#define MINHEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

#endif