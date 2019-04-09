//Compile with g++ (ver. 8.1.0)
//Task : Determine that the number is integer.
//Input : double
//Output : string

#include <iostream>

using namespace std;


int main (int argc , char* argv[])
{
    double number;
    cout << "Enter a number : ";
    cin >> number;
    
    
    if( int(number) != number )
    {
        cout << "This number is not integer!";
    }
    else
    {
        cout << "This number is integer!";
    }
    
    return 0;
}