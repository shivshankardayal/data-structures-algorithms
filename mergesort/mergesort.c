#include "mergesort.h"
#include <stdio.h>
#include <stddef.h>

void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}

/* l is for lowest index and h is highest index of the
sub-array of a to be sorted */
void mergesort(int a[], size_t l, size_t h)
{
    if (l < h)
    {
        // avoid overflow of mid calculation
        int m = l + (h - l) / 2;

        // Sort the two halves
        mergesort(a, l, m);
        mergesort(a, m + 1, h);

        merge(a, l, m, h);
    }
}
