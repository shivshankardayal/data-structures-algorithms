#include <stdio.h>
#include <stddef.h>
#include "linear_search.h"

int main()
{
    int a[] = {164, 384, 705, 592, 433, 211, 890, 777, 339};

    size_t n = sizeof(a) / sizeof(a[0]);
    linear_search(a, n);

    return 0;
}
