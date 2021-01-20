#include <stdio.h>

int main()
{
    int countTab = 0;
    int countSpace = 0;
    int count = 0;
    int c;
    int number = 0;

    while((c = getchar()) != EOF)
    {

        if(c == '\n')
        {
            if(count != 0)
                putchar(c);
            countTab = countSpace = count = 0;
        } 
        else if(c == ' ')
        {
            countSpace++;
            count++;
        }
        else if(c == '\t')
        {
            countTab++;
            count++;
        }
        else
        {
            count++;
            for(int i = 0; i < countTab; i++)
                putchar('\t');
            for(int i = 0; i < countSpace; i++)
                putchar(' ');
            countTab = countSpace = 0;
            putchar(c);
        }        
    }
    return 0;
}