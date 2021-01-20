#include <stdio.h>

int main()
{
	int c, sl, tl, nl;
	sl = 0;
	tl = 0;
	nl = 0;

	while((c = getchar()) != EOF)
	{
		if(c == ' ')
			++sl;
		if(c == '\t')
			++tl;
		if(c == '\n')
			++nl;
	}	
	printf("\nSpaces: %d\nTabs: %d\nLines: %d\n", sl, tl, nl);
	return 0;
}
