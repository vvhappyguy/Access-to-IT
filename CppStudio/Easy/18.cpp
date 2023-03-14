#include <iostream>

using namespace std;

int main()
{
    cout << "Program take dec-number in hex format." << endl;

    int number = 0;
    cout << "Enter number: ";
    cin >> number;
    cout << "Number " << number << " in hex means " << hex << number << endl;
    return 0;
}
