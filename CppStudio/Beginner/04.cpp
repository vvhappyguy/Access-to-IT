//Compile with g++ (ver. 8.1.0)
//Task : Convert meters in kilometers.
//Input : int
//Output: int

#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{

    double meters;
    double kilometers;
    
    cout << "Enter the number of metres: ";

    cin >> meters;

    if (meters < 0) 
    {
        cout << "The number of meters can not be negative\n";
        return 1;
    }
    
    kilometers = meters / 1000;
    cout << meters << " metres equals " << kilometers << '\n';
    
    return 0;
}