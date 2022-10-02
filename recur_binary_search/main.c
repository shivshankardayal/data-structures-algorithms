#include <stdio.h>
#include <stddef.h>
#include "binary_search.h"

int main()
{
    int a[] = {164, 211, 339, 384, 433, 592, 705, 777, 890};
    int search;

    printf("Enter value to find\n");
    scanf("%d", &search);
    size_t n = sizeof(a) / sizeof(a[0]);
    rbinary_search(a, 0, n - 1, search);

    return 0;
}
