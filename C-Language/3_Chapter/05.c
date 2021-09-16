#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
    char buffer[100];
    int i = 31;

    printf("Number: %d\n", i);
    itob(i, buffer, 16);
    printf("Buffer : %s\n", buffer);

    printf("INT_MIN: %d\n", INT_MIN);
    itob(INT_MIN, buffer, 16);
    printf("Buffer : %s\n", buffer);

    return 0;
}

void itob(int n, char s[], int b)
{
    int i, sign;
    char digits[] = "0123456789ABCDEF";

    sign = n;

    i = 0;
    do
    {
        s[i++] = digits[n % b];
    } while (n /= b);
    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}