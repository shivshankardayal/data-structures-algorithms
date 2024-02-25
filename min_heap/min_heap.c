#include "min_heap.h"

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
    int right = index * 2 + 2;                                      //count = 3 size=8         |8|10|3|2||
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
    heap->count++;                                     // count 2 size 4       |3|10|||
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

int top(Heap *heap)
{
    if (heap->count != 0)
        return *(heap->p);
    else
        return INT_MIN;
}
