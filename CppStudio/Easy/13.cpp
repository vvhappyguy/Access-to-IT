//Compile with g++ (ver. 8.1.0)
//Task : Determine if there are identical digits in a three-digit number.
//Input : int
//Output : string

#include <iostream>
#include <cmath>

using namespace std;

int main (int argc , char * argv[])
{
    int number;
    int first;
    int second;
    int third;

    cout << "Enter a three-digit number: ";
    cin >> number;

    if( number > 99 && number < 1000 ) 
    {
        third = number % 10;
        second = (number/10) % 10;
        first = number/100;

        if ( first == second || first == third || second == third )
        {
            cout << "The number " << number << " has the same numbers." ;
        }
        else 
        {
            cout << "The number " << number << " has not the same numbers." ; 
        }
    }
    else 
    {
        cout << "Number must be three-digit!";
        return 1; 
    }

   

    return 0;
}