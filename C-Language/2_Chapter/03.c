#include <stdio.h>
#include <ctype.h>

#define MAXLINE 10

int htoi(const char*);
int getline_my(char line[], int maxline);

int main()
{
    int len;
    char line[MAXLINE];

    while((len = getline_my(line, MAXLINE)) > 0)
    {
        printf("%d\n",htoi(line));
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

int htoi(const char* s) {

    int hexdigit = 0;
    int i = 0;
    int isEnd = 1;
    int n = 0;

    if (s[i] == '0') {
        i++;
        if (tolower(s[i]) == 'x')
            i++;
    }
    // printf("%d, inhex",inhex);

   while (isEnd) {
        int clower = tolower(s[i]);
        if (isdigit(clower))
            hexdigit = s[i] - '0';
        else if ('a' <= clower && clower <= 'f')
            hexdigit = clower - 'a' + 10;
        else
            isEnd = 0;
        if (isEnd)
            n = (n << 4) + hexdigit;  
        i++;
    }

    return n;
}