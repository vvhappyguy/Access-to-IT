#include <stdio.h>

int main()
{
	int c = 0, ns = 0;

	while((c = getchar()) != EOF)
	{
		if(c == ' ' && ns < 1)
		{
			++ns;
			putchar(c);
		}
		if(c == '\n')
			ns = 0;
	}
	return 0;
}
