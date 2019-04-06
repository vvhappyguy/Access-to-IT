//Compile with g++ (ver. 8.1.0)
//Task : Сalculate function value : y = ctg^2(ln(x))
//      For x from [a,b] with step h.
//input : int , int , int
//Output : int

#include <iostream>
#include <cmath>

using namespace std;


int main (int argc , char* argv[])
{
    double y;
    double h;
    double a;
    double b;

    cout << "Enter bounds for x [a,b] : ";
    cin >> a >> b; 


    if(a <= 0) 
    {
        cout << "For Ln(x) , x must be positive!";
        return 1;
    }

    if(a > b) 
    {
        cout << "Incorrect segment, 'a' must be less then 'b'. ";
        return 1;
    }

    cout << "Enter step for this bounds: ";
    cin >> h;

    if(h > abs(a-b))
    {
        cout << "Step must be less then |a-b|.";
        return 1;
    }

    cout << "y = ";

    for(a; a < b; a += h)
    {
        y = pow( cos(log(a)) / sin(log(a)) , 2);
        cout << y << "; ";
    }

    return 0;
}