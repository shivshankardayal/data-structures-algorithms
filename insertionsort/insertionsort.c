#include "insertionsort.h"
#include <stddef.h>

void insertionsort(int *a, size_t n)
{
    int i, k, y;

    for (k = 1; k < n; k++)
    {
        y = a[k];
        for (i = k - 1; i >= 0 && y < a[i]; i--)
            a[i + 1] = a[i];
        
        a[i + 1] = y;
    }
}