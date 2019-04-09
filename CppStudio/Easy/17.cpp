//Compile with g++ (ver. 8.1.0)
//Task : Find the number in the set at a specific position.
//input : char[] , int
//Output : int

#include <iostream>
#include <string>

using namespace std;


int main (int argc , char* argv[])
{
    string set;
    int pos;

    cout << "Enter set of number : ";
    cin >> set; 

    cout << "Enter position of digit: ";
    cin >> pos;

    if( (pos-1) >= set.size() || (pos-1) < 0)
    {
        cout << "Digit with this position does not exist!";
        return 1;
    }
    else
    {
        cout << pos << " - digit of set = " << set[pos-1];
    } 

    return 0;
}