#include <stdio.h>
#define MINLINE 80

int clearLine(char line[], int maxline);

int main()
{
    char line[MINLINE];
    int c;
    int number = 0;

    while((c = getchar()) != EOF)
    {
        if(c == '\n')
        {
            if(number > MINLINE)
                putchar(c);
            number = 0;
            clearLine(line, MINLINE);
        }
        else if(number < MINLINE)
        {
            line[number] = c;
            number++;
        }
        else if(number == MINLINE)
        {
            number++;
            for(int i = 0; i < MINLINE; i++)
                putchar(line[i]);
            clearLine(line, MINLINE);
            putchar(c);
        }
        else
        {
            putchar(c);
        }
    }
    return 0;
}

int clearLine(char line[], int maxline)
{
    for(int i = 0; i < maxline; i++)
        line[i] = 0;
}