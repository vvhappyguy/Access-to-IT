#include <stdio.h>

int bitcount(unsigned x);

int main()
{
    printf("%d",bitcount(15));
    return 0;
}

int bitcount(unsigned x)
{
    int b = 1;

    while((x &= (x-1)) != 0)
            b++;
    return b;
}