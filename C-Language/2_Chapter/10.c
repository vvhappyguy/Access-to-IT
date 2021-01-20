#include <stdio.h>

char lower(char _str);

int main()
{
    printf("%c", lower('c'));
    return 0;
}

char lower(char _str)
{
    return _str = (_str >= 'A' && _str <= 'Z') ? _str+'a'-'A' : _str;
}