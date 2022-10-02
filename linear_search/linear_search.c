#include <stdio.h>
#include <stddef.h>
#include "linear_search.h"

void linear_search(int *a, size_t n)
{
    int element_to_be_searched = 0;

    printf("Enter the element to be searched:\n");
    scanf("%d", &element_to_be_searched);

    for (size_t i = 0; i < n; i++)
    {
        if (a[i] == element_to_be_searched)
        {
            printf("Element %d found at %luth location\n", element_to_be_searched, i + 1);
            return;
        }
    }

    printf("Given element not found!\n");
}
