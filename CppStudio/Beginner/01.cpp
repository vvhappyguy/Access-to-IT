//Compile with g++ (ver. 8.1.0)
//Task : Divide a five-digit number into digits.
//Input : int
//Output: int

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    int number;
    int temp = 10000;
    
    cout << "Enter number in the range from 10.000 to 99.999.\n";

    cin >> number;

    if (number > 99999) 
    {
        cout << "Number out of range!\n";
        return 1;
    }
    else if (number < 10000)  
    {
        cout << "Number out of range!\n";
        return 1;
    }

    for (int i = 1; i <= 5; ++i)
    {
        cout << "[" << i << "] digit = " << number / temp << '\n';
        number %= temp;
        temp /= 10;
    }
    return 0;
}