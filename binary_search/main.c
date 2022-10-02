#include <stdio.h>
#include <stddef.h>
#include "binary_search.h"

int main()
{
    int a[] = {164, 211, 339, 384, 433, 592, 705, 777, 890};

    size_t n = sizeof(a) / sizeof(a[0]);
    binary_search(a, 0, n - 1);

    return 0;
}
