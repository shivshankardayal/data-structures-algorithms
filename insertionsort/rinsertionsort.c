#include "rinsertionsort.h"
#include <stddef.h>

void rinsertionsort(int *a, size_t n)
{
    if (n <= 1)
        return;

    rinsertionsort(a, n-1 );
 
    int y = a[n-1];
    int j = n-2;

    while (j >= 0 && a[j] > y)
    {
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = y;
}