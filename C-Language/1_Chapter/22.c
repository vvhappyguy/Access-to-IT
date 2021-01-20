#include <stdio.h>

#define COLUMN 5

int main()
{
	int count = 0;
	int c;
	while((c = getchar())  != EOF)
   	{
   	        count++;
		if(c == ' ' && count >= COLUMN)
		{
			putchar('\n');
			count = 0;
		}
		else
			putchar(c);
   	}
	return 0;
}
