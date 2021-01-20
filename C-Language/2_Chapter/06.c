#include <stdio.h>

// TODO: Add test cases for task 
// For example 167 is correct for program functions hard-code values

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // printf("0%o 0%o 0%o\n", (~(~0 << n) & y), (~0<<(n+p-1)) & x , (~(~0 << (p-1)) & x));
    return (~(~0 << n) & y) | (~0<<(n+p-1)) & x | (~(~0 << (p-1)) & x);
}

int main(void)
{  
    int i = 31;
    printf("%d", setbits(172,2,3,255));
    return 0;
}
