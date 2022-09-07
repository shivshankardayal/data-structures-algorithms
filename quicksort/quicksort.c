#include "quicksort.h"
#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int *a, int low, int high)
{
    // there are four typical ways to choose pivot
    // 1st, last, mid and random. however you can choose any
    // element as pivot(well that is what random implies)
    int pivot = a[high];
    size_t i = (low - 1);

    printf("low=%d high=%d pivot=%d\n", low, high, pivot);

    for (size_t j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
            printf("%d %d\n", a[i], a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    printf("%d %d\n", a[i +1], a[high]);
    return (i + 1);
}

// 4       3       2       1
// low = 0
// high = 3
// i = -1
// 1       3       2       4
// pi = 0
// low = 1
// high = 3
// i = 0
// 1       3       2        4
// pi = 3
// low = 1
// high = 2

void quicksort(int *a, int low, int high)
{
    if (low < high)
    {
        int pi = partition(a, low, high);
        quicksort(a, low, pi - 1);
        quicksort(a, pi + 1, high);
    }
}