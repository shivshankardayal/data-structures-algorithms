#include "selectionsort.h"
#include <stdio.h>
#include <stddef.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionsort(int *a, size_t n)
{
    int i, j, min_idx;

    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }
    printf("\n");
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        if (min_idx != i)
            swap(&a[min_idx], &a[i]);

        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}