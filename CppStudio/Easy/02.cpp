#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    size_t N = 0;
    size_t k = 1;

    size_t sum = 0;

    cout << "Enter N: ";
    cin >> N;
    cout << "Enter k: ";
    cin >> k;

    for(size_t i = 1; i <= N; i++)
    {
        sum += pow(i,k);
    }

    cout << "Sum = " << sum << endl;

    return 0;
}