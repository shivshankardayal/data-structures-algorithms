#include "shellsort.h"
#include <stdio.h>
#include <stddef.h>

void shellsort(int *a, size_t n)
{
    int gaps[8] = {701, 301, 132, 57, 23, 10, 4, 1};
    for (int g = 0; g < 8; g++)
    {
        int gap = gaps[g];
        // Do a gapped insertion sort for every elements in gaps
        // Each loop leaves a[0..gap-1] in gapped order
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            int temp = a[i];

            // shift earlier gap-sorted elements up until the correct
            // location for a[i] is found
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];

            //  put temp (the original a[i]) in its correct location
            a[j] = temp;
        }
    }
}