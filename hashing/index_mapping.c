#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 1000

bool hash[MAX + 1][2];

bool search(int X)
{
    if (X >= 0)
    {
        if (hash[X][0] == 1)
            return true;
        else
            return false;
    }

    X = abs(X);
    if (hash[X][1] == 1)
        return true;

    return false;
}

void insert(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            hash[a[i]][0] = 1;
        else
            hash[abs(a[i])][1] = 1;
    }
}

int main()
{
    int a[] = {-1, 9, -5, -8, 5, -2, -20, 25, 45, 28, -33, 78, 67, -96};
    int n = sizeof(a) / sizeof(a[0]);

    insert(a, n);

    int i = 0;

    printf("Enter a key to be searched in hash table:\n");
    scanf("%d", &i);

    if (search(i) == true)
        printf("The key is in the hash table.\n");
    else
        printf("The key is not in the hash table.\n");

    return 0;
}