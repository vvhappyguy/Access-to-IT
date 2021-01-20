#include <stdio.h>

int main()
{
	int upper, lower, step;
	float fahr, celsius;
	
	upper = 300;
	lower = 0;
	step = 20;

	fahr = 0;
	while(fahr <= 9)
	{
		printf("*");
		fahr += 1;
	}
	printf("\n* Table  *\n");
	while(fahr <= 19)
	{
		printf("*");
		fahr += 1;
	}
	printf("\n");

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr += step;
	}

	return 0;
}
