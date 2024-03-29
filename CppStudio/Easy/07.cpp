// Compile with g++ (ver. 8.1.0)
// Task : Сalculate vector length.
// Input : double , double , double
// Output : double

#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

    double x;
    double y;
    double z;
    double length;

    cout << "Enter X: ";
    cin >> x;

    cout << "Enter Y: ";
    cin >> y;

    cout << "Enter Z: ";
    cin >> z;

    length = sqrt(x * x + y * y + z * z);

    cout << "Length = " << length;

    return 0;
}