#include <stddef.h>
#include <stdbool.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// implementation of  bubble sort
void bubblesort(int *a, size_t n)
{
    size_t i, j;
    bool flag = false;

    for (i = 0; i < n - 1; i++)
    {
        flag = false;
        for (j = 0; j < n - i - 1; j++)
        {

            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = true;
            }
        }
        if (!flag)
            break;
    }
}