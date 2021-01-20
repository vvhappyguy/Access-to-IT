// TODO: Add vertical histogram
#include <stdio.h>

int main()
{
	int c = 0;
    int count = 0;
	while((c = getchar()) != EOF)
	{
		if((c == '\t' || c == ' ' || c == '\n')) 
        {
            for(int i = 0; i < count; i++)
                putchar('*');
            if(count > 0)
                putchar('\n');
            count = 0;
        }	
        else
            count++;   
	}
	return 0;
}