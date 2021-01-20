#include <stdio.h>

unsigned rightrot(unsigned x, int n)
{
    unsigned y = x;
    unsigned l = 0;
    while (y > 0)
    {
        // printf("%d\n", y);
        y = y >> 1;
        l++;
    }
    // printf("l:%d\n", l);
    n %= l;

    unsigned t = 1 << l ;
    // printf("t:%d\n", t);
        
    for(int i = 0; i < n; i++)
    {
        if(x % 2 == 1)
            x |= t; 
        x = x >> 1;
    }
    return x;
}

int main(void)
{  
    printf("%x\n", rightrot(0x5, 4) );
    return 0;
}
