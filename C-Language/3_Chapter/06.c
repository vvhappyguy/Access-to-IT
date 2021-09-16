#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>

void itoa(int n, char s[], int field);
void reverse(char s[]);

int main(void)
{
    char buffer[20];
    int i = 35;

    printf("Number: %d\n", i);
    itoa(i, buffer, 10);
    printf("Buffer : %s\n", buffer);

    printf("INT_MIN: %d\n", INT_MIN);
    itoa(INT_MIN, buffer, 4);
    printf("Buffer : %s\n", buffer);

    return 0;
}

void itoa(int n, char s[], int field)
{
    int i, sign;
    sign = n;

    i = 0;
    do
    {
        s[i++] = abs(n % 10) + '0';
    } while (n /= 10);
    if (sign < 0)
        s[i++] = '-';
    while (field > i)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}