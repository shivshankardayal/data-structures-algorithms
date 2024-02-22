#ifndef MINHEAP_H
#define MINHEAP_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct max_heap
{
    int *p;
    int size;
    int count;
} Heap;

Heap *create_heap(Heap *heap);
void heap_up(Heap *heap, int index);
void heap_down(Heap *heap, int index);
void push(Heap *heap, int x);
void pop(Heap *heap);
int top(Heap *heap);
int size(Heap *heap);

#endif