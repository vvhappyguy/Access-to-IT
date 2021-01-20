#include <stdio.h>
#define MAXLINE 1000

int getline_my(char line[], int maxline);
void reverse(char s[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    
    max = 0;
    while((len = getline_my(line, MAXLINE)) > 0)
    {
            reverse(line);
            printf("%s", line);
    }
    return 0;
}

int getline_my(char s[], int lim)
{
    int c, i;

    for(i = 0; (c=getchar())!=EOF && c!='\n'; ++i)
    {
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

void reverse(char s[]) 
{

    size_t i = 0;
    size_t j = 0;

    while (s[i] != '\0')
        ++i;
    --i;

    if (i > 0 && s[i] == '\n')
        --i;

    if (i < 1)
        return;

    while (j < i) {
        char   temp;
        temp   = s[j];
        s[j++] = s[i];
        s[i--] = temp;
    }
}