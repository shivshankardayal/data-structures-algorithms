#include "radixsort.h"
#include <stdio.h>
#include <stddef.h>

int max(int *a, size_t n)
{
    int max = a[0];

    for (size_t i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    return max;
}

void countsort(int *a, size_t n, int exp, int base)
{
    int output[n];
    int count[10] = {0};

    for (size_t i = 0; i < n; i++)
        count[(a[i] / exp) % base]++;

    for (size_t i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(a[i] / exp) % base] - 1] = a[i];
        count[(a[i] / exp) % base]--;
    }

    for (size_t i = 0; i < n; i++)
        a[i] = output[i];
}

void radixsort(int *a, size_t n)
{
    int m = max(a, n);
    int base = 10;

    // Do counting sort for every digit.
    for (int exp = 1; m / exp > 0; exp *= 10)
        countsort(a, n, exp, base);
}