#include "insertionsort.h"
#include <stdio.h>
#include <stddef.h>

void insertionsort(int *a, size_t n)
{
    int i, j, y;

    for (j = 1; j < n; j++)
    {
        y = a[j];
        for (i = j - 1; i >= 0 && y < a[i]; i--)
        {
            a[i + 1] = a[i];
            for (int k = 0; k < n; k++)
            {
                printf("%d ", a[k]);
            }
            printf("\n");
        }

        a[i + 1] = y;

        for (int k = 0; k < n; k++)
        {
            printf("%d ", a[k]);
        }
        printf("\n");
    }
}