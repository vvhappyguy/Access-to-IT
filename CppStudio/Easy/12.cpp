#include <iostream>

using namespace std;

int main()
{
	cout << "Detecting part by coorinates: x,y (x*y != 0)" << endl;
	int x = 0;
	int y = 0;
	cout << "Enter x: ";
	cin >> x;
	cout << "Enter y: ";
	cin >> y;

	if((x == 0)|| (y == 0))
	{
		cout << "(x * y) can't be 0." << endl;
		return 1;
	}

	if(x * y < 0)
	{
		if(x > 0)
		{
			cout << "Fourth (IV) part." << endl;
		}
		else
		{
			cout << "Second (II) part." << endl;
		}
	}
	else
	{
		if(x > 0)
		{
			cout << "First (I) part." << endl;
		}
		else
		{
			cout << "Third (III) part." << endl;
		}
	}
	return 0;
}
