#include <iostream>
#include <cmath>

using namespace std;

#define PI 3.14159265358979323846

int main()
{
    size_t n = 0;
    cout << "Enter n: ";
    cin >> n;

    double_t sum = 0;
    double_t sin_sum = 0;

    for(size_t i = 1; i <= n; i++)
    {
        sin_sum += sin(i * PI / 180);
        sum += 1 / sin_sum;
    }

    cout << "Sum = " << sum << endl;

    return 0;
}