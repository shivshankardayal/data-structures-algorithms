#include "rselectionsort.h"
#include <stdio.h>
#include <stddef.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int min_index(int a[], int i, int j)
{
    if (i == j)
        return i;
 
    // Find minimum of remaining elements
    int k = min_index(a, i + 1, j);
 
    // Return minimum of current and remaining.
    return (a[i] < a[k])? i : k;
}

void rselectionsort(int *a, size_t n, size_t initial_index)
{
    if (initial_index == n)
       return;
 
    // calling minimum index function for minimum index
    int k = min_index(a, initial_index, n-1);
 
    // Swapping when index and minimum index are not same
    if (k != initial_index)
       swap(&a[k], &a[initial_index]);
 
    // Recursively calling selection sort function
    rselectionsort(a, n, initial_index + 1);
}