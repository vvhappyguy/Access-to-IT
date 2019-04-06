//Compile with g++ (ver. 8.1.0)
//Task : Сalculate function value : z(x,y) = (1-tg(x)) ^ ctg(x) + cos(x-y)
//Input : int , int
//Output : int


#include <iostream>
#include <cmath>

using namespace std;

int main (int argc, char* argv[])
{
    constexpr double Pi = 3.14159;
    double z = 1;
    double x = 1;
    double y = 1;
    double ctgX = 1;

    cout << "Enter X: ";
    cin >> x;

    if(x == 0)
    {
        cout << "Value of X must not be zero!";
        return 1;
    }

    cout << "Enter Y: ";
    cin >> y;
    
    x *= Pi/180;
    y *= Pi/180;

    ctgX = cos(x) / sin(x);

    z = pow(1-tan(x), ctgX) + cos(x - y);

    cout << "Value = " << z;

    return 0;
}