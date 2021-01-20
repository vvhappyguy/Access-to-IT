#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    unsigned old = ((~0 << (n+p-1)) | ~(~0 << (p-1))) & x;
    unsigned new = ~(~old & x);
    return old | new; 
}

int main(void)
{  
    int n = 3;
    int p = 1;
    int x = 0xf;
    printf("%x\n", invert(0xad, 1, 4) );
    return 0;
}
