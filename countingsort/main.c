#include <stdio.h>
#include <stddef.h>

#include "countsort.h"


void print(int *a, size_t n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

// Driver function
int main()
{
    int a[] = {-7, -6, -5, -10, 0, -3, -3, 8, -9, 5, -1, 10};

    size_t n = sizeof(a) / sizeof(a[0]);
    countsort(a, n);
    printf("Sorted array: \n");
    print(a, n);

    return 0;
}