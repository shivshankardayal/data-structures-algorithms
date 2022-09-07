#include <stdio.h>

#include "quicksort.h"

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
    // int a[] = {164, 384, 705, 592, 433, 211, 890, 777, 339};
    // int a[] = {4, 3, 2, 1};
    int a[] = {1, 2, 3, 4};
    size_t n = sizeof(a) / sizeof(a[0]);
    quicksort(a, 0, n - 1);
    printf("Sorted array: \n");
    print(a, n);

    return 0;
}