#include <stdio.h>
#include <stddef.h>

#include "radixsort.h"


void print(int *a, size_t n)
{
    size_t i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Driver function
int main()
{
    int a[] = {164, 384, 705, 592, 433, 211, 890, 777, 339};

    size_t n = sizeof(a) / sizeof(a[0]);
    radixsort(a, n);
    printf("Sorted array: \n");
    print(a, n);

    return 0;
}