// deltab
#include <stdio.h>

#define SPACESINTAB 7

int main()
{
    char spaces[SPACESINTAB + 1];
    for(int i = 0; i < SPACESINTAB; i++)
        spaces[i] = ' ';
    spaces[SPACESINTAB] = 0;

    int c;
    while((c = getchar())  != EOF)
    {
        if(c  == '\t')
            printf("%s", spaces);
        else
            putchar(c);
    }
    return 0;
}