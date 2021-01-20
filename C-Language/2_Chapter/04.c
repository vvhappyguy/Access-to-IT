#include <stdio.h>

void squeeze(char*,char*);

int main(void)
{
    char a[] = "abcd";
    char b[] = "b";
    squeeze(a, b);
    printf("%s", a);
    return 0;
}

void squeeze(char s[], char delete[]) {

    int i;
    int j;

    for (i = 0, j = 0; s[i] != '\0'; i++) 
    {
        int k;
        int keep;

        for (keep = 1, k = 0; delete[k] != '\0' && keep; k++)
            keep = (s[i] != delete[k]);
        if (keep)
            s[j++] = s[i];
    }

    s[j] = '\0';
}