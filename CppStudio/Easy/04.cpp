//Compile with g++ (ver. 8.1.0)
//Task : Сalculate angle value.
//Input : double , double
//Output : double

#include <iostream>
#include <cmath>

using namespace std;

int main (int argc , char * argv[])
{
    constexpr double g = 9.8;
    constexpr double Pi = 3.14159;

    double speed;
    double time;
    double angle;

    cout << "Enter V: ";
    cin >> speed;

    if(speed < 0)
    {
        cout << "Incorrect speed, must be positive!";
        return 1;
    }

    cout << "Enter T: ";
    cin >> time;

    if(time < 0)
    {
        cout << "Incorrect time, must be positive!";
        return 1;
    }

    angle = asin((g * time) / (2 * speed) ) * (180/Pi);

    cout << "Angle = " << angle;

    return 0;
}