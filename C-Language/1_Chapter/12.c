#include <stdio.h>

int main()
{
	int c = 0;
	while((c = getchar()) != EOF)
	{
		if(c == '\t' || c == ' ') 
			putchar('\n');
        else
            putchar(c);
	}
	return 0;
}