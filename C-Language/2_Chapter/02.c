// !!! Just change for(i = 0; ((i < lim - 1) + ((c=getchar())!=EOF) + (c!='\n')) == 3; ++i)

#include <stdio.h>
#define MAXLINE 5

int getline_my(char line[], int maxline);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    
    max = 0;
    while((len = getline_my(line, MAXLINE)) > 0)
    {
            printf("%s", line);
    }
    return 0;
}

int getline_my(char s[], int lim)
{
    int c, i;

    for(i = 0; ((i < lim - 1) + ((c=getchar())!=EOF) + (c!='\n')) == 3; ++i)
    {
        //printf("((i < lim - 1) + ((c=getchar())!=EOF) + (c!='\n')): %d\n",((i < lim - 1) + ((c=getchar())!=EOF) + (c!='\n')));
        if(i < lim - 1)
            s[i] = c;
        else if(i == lim - 1)
            s[i] = '\0';
    }
        
    if(c == '\n' && i < lim - 1){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
