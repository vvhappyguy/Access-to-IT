// Program takes simple checks of c syntax {} [] () '' "" // /**/
// {} +
// [] +
// () +
// '' -
// "" -
// // -
// /**/ -
#include "stdio.h"

int main(void)
{
	int c;
	int type1 = 0; // ()
	int type2 = 0; // {}
	int type3 = 0; // []
	while((c = getchar()) != EOF)
	{
		switch (c)
		{
		case '{':
			type2++;
			break;
		case '}':
			type2--;
			break;
		case '(':
			type1++;
			break;
		case ')':
			type1--;
			break;
		case '[':
			type3++;
			break;
		case ']':
			type3--;
			break;
		default:
			break;
		}
	}
	if(type1 != 0)
		printf("Problem with () %d\n", type1);
	if(type2 != 0)
		printf("Problem with {} %d\n", type2);
	if(type3 != 0)
		printf("Problem with [] %d\n", type3);
	return 0;
}
