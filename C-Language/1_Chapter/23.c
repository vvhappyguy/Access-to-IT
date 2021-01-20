// Program deletes C/C++ comments from input char stream
#include "stdio.h"

int main(void)
{
	int lastSymbols[2];
	lastSymbols[1] = ' ';
	int c;
	int state = 0;
	while((c = getchar()) != EOF)
	{
		// Check this type of comment
		lastSymbols[0] = lastSymbols[1];
		lastSymbols[1] = c;
		if(lastSymbols[0] == '/' && lastSymbols[1] == '/')
		{
			lastSymbols[0] =  lastSymbols[1] = ' ';
			while((c = getchar()) != EOF)
				if(c == '\n')
				{
					putchar(c);
					state = -1;
					break;
				}
					
		}
		/* Check this type of comment */
		else if(lastSymbols[0] == '/' && lastSymbols[1] == '*')
		{
			lastSymbols[0] = ' ';
			lastSymbols[1] = ' ';
			while((c = getchar()) != EOF)
			{
				lastSymbols[0] = lastSymbols[1];
				lastSymbols[1] = c;
				if(lastSymbols[0] == '*' && lastSymbols[1] == '/')
				{
					state = -1;
					lastSymbols[0] = -1;
					lastSymbols[1] = -1;
					break;
				}
			}
		}
		else if(state > 0)
		{
			putchar(lastSymbols[0]);
		}
		state += 1;
	}
	return 0;
}
