// Compile with g++ (gcc ver. 8.2.0)
// 24. Сумма 1/sin(1) + 1/(sin(1) + sin(2)) + … + 1/(sin(1)+sin(2)+…+sin(n))
// Вычислить сумму 1/sin1+1/(sin1+sin2)+…1/(sin1+…+sinn),
// где n — заданное натуральное число.
// Input: n
// Output: sum

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