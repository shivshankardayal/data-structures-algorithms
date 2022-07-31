#include <stddef.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// implementation of recursive bubble sort
void bubblesort(int *a, size_t n)
{
    size_t i, j;
    bool already_sorted = true;

    if (n == 1)
        return;


    for (i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])
        {
            swap(&a[i], &a[i + 1]);
            already_sorted = false;
        }
    }

    if (already_sorted)
        return;

    bubblesort(a, n-1);
}