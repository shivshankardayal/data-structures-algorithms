#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXSIZE 97
const int MOD = 97;

typedef struct element
{
    int value;
    struct element *next;
} Element;

typedef struct hash
{
    Element **chain;
    int size;
} Hash;

void put(Hash *h, int v)
{
    int mod = v % MOD;

    for (Element *i = h->chain[mod]; i != NULL; i = i->next)
    {
        if (i->value == v)
        {
            return;
        }
    }

    Element *e = malloc(sizeof(Element));

    e->value = v;
    e->next = h->chain[mod];
    h->chain[mod] = e;
}

Hash *initialize()
{
    Hash *h = malloc(sizeof(Hash));
    h->size = MAXSIZE;
    h->chain = malloc(MAXSIZE * sizeof(Element *));

    for (int i = 0; i < MAXSIZE; i++)
    {
        h->chain[i] = NULL;
    }

    return h;
}

bool contains(Hash *h, int v)
{
    int mod = v % MOD;

    for (Element *i = h->chain[mod]; i != NULL; i = i->next)
    {
        if (i->value == v)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Hash *h;

    h = initialize();

    put(h, 56);
    put(h, 36);
    put(h, 22);
    put(h, 67);
    put(h, 85);
    put(h, 9);
    put(h, 19);
    put(h, 1);
    put(h, 98);
    put(h, 195);

    if (contains(h, 56))
        printf("Value found!\n");
    else
        printf("Value not found!\n");
    if (contains(h, 58))
        printf("Value found!\n");
    else
        printf("Value not found!\n");
    if (contains(h, 1))
        printf("Value found!\n");
    else
        printf("Value not found!\n");
    if (contains(h, 98))
        printf("Value found!\n");
    else
        printf("Value not found!\n");
    if (contains(h, 195))
        printf("Value found!\n");
    else
        printf("Value not found!\n");

    return EXIT_SUCCESS;
}


// MOD 97
// |1|->|98|->|195|
// |2|->|99|->|196|
// ... 97 times
// ||