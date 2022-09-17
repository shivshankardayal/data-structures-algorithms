#include "countsort.h"
#include <stdio.h>
#include <stddef.h>
#include <string.h>

void countsort(int *a, size_t n)
{
    int max = a[0], min = a[0];

    for (int i = 0; i < n; i++)
        if (min > a[i])
            min = a[i];
    for (int i = 0; i < n; i++)
        if (max < a[i])
            max = a[i];

    int range = max - min + 1;

    int count[range], output[range];

    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        count[a[i] - min]++;

    // Change count[i] so that count[i] contains actual
    // position of this character in output array
    for (int i = 1; i < range; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < range; i++)
        printf("%d,%d ", i,count[i]);
    printf("\n");

    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i] - min] - 1] = a[i];
        printf("%d,%d,%d ", a[i], output[count[a[i] - min] - 1], count[a[i]-min]);
        count[a[i] - min]--;
    }
    printf("\n");

    for (int i = 0; i < n; ++i)
        a[i] = output[i];
}