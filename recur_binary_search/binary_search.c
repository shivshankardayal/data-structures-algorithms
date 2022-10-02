#include <stdio.h>
#include <stddef.h>
#include "binary_search.h"

void rbinary_search(int *a, size_t first, size_t last, int search)
{
    size_t middle = first + (last - first) / 2;

    if (first > last)
    {
        printf("Not found! %d is not present in the list.\n", search);
        return;
    }
    else
    {
        if (a[middle] < search)
            first = middle + 1;
        else if (a[middle] == search)
        {
            printf("%d found at location %zu.\n", search, middle + 1);
            return;
        }
        else
            last = middle - 1;
    }

    rbinary_search(a, first, last, search);
}
