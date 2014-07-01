#include "libstuff.h"

int
one(void)
{
    return 1;
}

int
two(void)
{
    return 1 << 1;
}

int
multiply(int a, int b)
{
    int t = 0;
    for( ; a > 0; a--)
    {
        t += b;
    }
    return t;
}
