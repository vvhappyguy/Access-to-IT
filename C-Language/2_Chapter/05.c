#include <stdio.h>

int any(char*,char*);

int main(void)
{
    char a[] = "acd";
    char b[] = "b";    
    printf("%d", any(a,b));
    return 0;
}

int any(char s[], char delete[]) 
{

    int i;

    for (i = 0; s[i] != '\0'; i++) 
    {
        int k;

        for (k = 0; delete[k] != '\0'; k++)
            if(delete[k] == s[i])
                return i;
            
    }
    return -1;
}