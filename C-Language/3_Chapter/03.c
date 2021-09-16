#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define STR_SIZE 256

void expand(char s1[], char s2[]);

int main()
{
    char input[STR_SIZE] = "a-z1-9-1-3-6";
    char output[STR_SIZE] = "";
    expand(input, output);
    printf("%s\n", output);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    char t;

    for (i = 0, j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == '-')
        {
            if ((isdigit(s1[i - 1]) && isdigit(s1[i + 1]) && (s1[i - 1] < s1[i + 1])) ||
                (islower(s1[i - 1]) && islower(s1[i + 1]) && (s1[i - 1] < s1[i + 1])) ||
                (isupper(s1[i - 1]) && isupper(s1[i + 1]) && (s1[i - 1] < s1[i + 1])))
                for (t = (char)(s1[i - 1] + 1); t < s1[i + 1]; t++)
                    s2[j++] = t;
            else
                s2[j++] = s1[i];
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
};
