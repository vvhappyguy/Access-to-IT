// deltab
#include <stdio.h>

#define SPACESINTAB 7

int main()
{
    char spaces[SPACESINTAB + 1];
    for(int i = 0; i < SPACESINTAB; i++)
        spaces[i] = ' ';
    spaces[SPACESINTAB] = 0;

    int flagSpaceString = 0; 
    int c;
    while((c = getchar())  != EOF)
    {
        if(c  == ' ' && flagSpaceString != -1)
        {
            flagSpaceString++;
        }
        else if(c == '\n')
        {
            if(flagSpaceString > 0)
                for(int i = 0; i < (flagSpaceString / SPACESINTAB); i++)
                    putchar('\t');
                for(int i = 0; i < (flagSpaceString % SPACESINTAB); i++)
                    putchar('_');
            flagSpaceString = 0;
            putchar('\n');
        }
        else
        {
            for(int i = 0; i < flagSpaceString; i++)
                putchar(' ');
            flagSpaceString = -1;
            putchar(c);
        }
            
    }
    return 0;
}