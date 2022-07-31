#include <stdio.h>

void f(unsigned int i)
{
    printf("%u\n", i);
    f(++i);
}

int main()
{
    unsigned int i = 0;

    f(i);

    return 0;
}