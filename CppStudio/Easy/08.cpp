//Compile with g++ (ver. 8.1.0)
//Task : Сalculate function value : z(x,m) = x^m*sin^m(xm)
//     For m from 1 to 5 with step 1.
//     For x from -1.1 to 0.3 with step 0.2.


#include <iostream>
#include <cmath>

using namespace std;

int main (int argc, char* argv[])
{
    double z = 1;
    double tempX;
    double tempSIN;

    for (double x = -1.1; x <= 0.3; x += 0.2)
    {
        cout << "When x = " << x << endl;

        for(int m = 1; m < 5; ++m)
        {
            tempX = 1;
            tempSIN = 1;

            for (int i = 0; i < m; ++i)
            {
                tempX *= x;
                tempSIN *= sin(x*m); 
            }

            z = tempX * tempSIN;
            cout << "Function value = " << z << ". When m = " << m << ".\n";
        }
        cout << endl;
    }

    return 0;
}