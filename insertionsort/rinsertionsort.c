#include "rinsertionsort.h"
#include <stddef.h>
#include <stdio.h>

void rinsertionsort(int *a, size_t n)
{
    if (n <= 1)
        return;
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    printf("\n");
    rinsertionsort(a, n - 1);

    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    printf("\n");
    int y = a[n - 1];
    int j = n - 2;

    while (j >= 0 && a[j] > y)
    {
        a[j + 1] = a[j];
        j--;
    }
    a[j + 1] = y;
    for (int k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }

    printf("\n");
}