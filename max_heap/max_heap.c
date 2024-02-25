#include "max_heap.h"

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
	if (index >= heap->count)                          //         15 
		return;                                        //        /  \   count = 3 maximum = 18 left flag 1
	int left = index * 2 + 1;                          //       10   12
	int right = index * 2 + 2;                         //       /
	int leftflag = 0, rightflag = 0;                   //      18

	int maximum = *((heap->p) + index);
	if (left < heap->count && maximum < *((heap->p) + left))
	{
		maximum = *((heap->p) + left);
		leftflag = 1;
	}
	if (right < heap->count && maximum < *((heap->p) + right))
	{
		maximum = *((heap->p) + right);
		leftflag = 0;
		rightflag = 1;
	}
	if (leftflag)
	{
		*((heap->p) + left) = *((heap->p) + index);
		*((heap->p) + index) = maximum;
		heap_down(heap, left);
	}
	if (rightflag)
	{
		*((heap->p) + right) = *((heap->p) + index);
		*((heap->p) + index) = maximum;
		heap_down(heap, right);
	}
}

void heap_up(Heap *heap, int index)
{
	int parent = (index - 1) / 2;
	if (parent < 0)
		return;
	if (*((heap->p) + index) > *((heap->p) + parent))
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
	*((heap->p) + heap->count) = x; // count = 3  size = 8    18    |10|15|12|18|||||
	heap->count++;					// 18
	if (4 * heap->count >= 3 * heap->size)
	{ // 15 12
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

int empty(Heap *heap)
{
	if (heap->count != 0)
		return 0;
	else
		return 1;
}
