#include <stdio.h>
#include <stddef.h>
#include "binary_search.h"

void binary_search(int *a, size_t first, size_t last)
{
    int search;

    printf("Enter value to find\n");
    scanf("%d", &search);

    size_t middle = first + (last - first) / 2;

    while (first <= last)
    {
        if (a[middle] < search)
            first = middle + 1;
        else if (a[middle] == search)
        {
            printf("%d found at location %zu.\n", search, middle + 1);
            break;
        }
        else
            last = middle - 1;

        middle = first + (last - first) / 2;
    }
    if (first > last)
        printf("Not found! %d is not present in the list.\n", search);
}
