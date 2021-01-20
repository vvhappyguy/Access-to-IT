// Task in original: 
/*
Revise the main routine of the longest-line program so it will correctly print the length of arbitrarily long input lines,
and as much as possible of the text.
*/

#include <stdio.h>
#define MAXLINE 10

int getline_my(char line[], int maxline);
void copy(char to[],char from[]);

int main()
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    
    max = 0;
    while((len = getline_my(line, MAXLINE)) > 0)
        if(len > max){
            max = len;
            copy(longest, line);
        }
    if(max > 0)
        printf("max: %d \nstring(as possible):%s\n",max,  longest);
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

void copy(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}