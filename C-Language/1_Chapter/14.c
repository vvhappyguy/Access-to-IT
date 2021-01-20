#include <stdio.h>
// 0x7e - 0x20
#define ASCII_SIZE (126 - 32)

int main()
{
	int c = 0;
    int symbols[ASCII_SIZE];
    for(int i = 0; i < ASCII_SIZE; i++)
        symbols[i] = 0;

	while((c = getchar()) != EOF) 
	{
		symbols[c-32]++;
        if(c == '\n')
        {
            for(int i = 0; i < ASCII_SIZE; i++)
            {
                putchar(i+32);
                putchar(' ');
                for(int j = 0; j < symbols[i]; j++)
                    putchar('*');
                putchar('\n');
            }
            for(int i = 0; i < ASCII_SIZE; i++)
                    symbols[i] = 0;
        }
	}
	return 0;
}