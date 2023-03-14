// compiled with clang (10.0.1)
// 5. Возведение числа в степень
// Input: int, int
// Output: int

#include <iostream>
using namespace std;

int main()
{
    int number, power, result;
    result = 1;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the power: ";
    cin >> power;
    if (power < 0)
    {
        cout << "Введите неотрицательное число!" << endl;
        return 1;
    }
    switch (power)
    {
        case 0:
            cout << "number = 1" << endl;
            break;
        default:
            for (int i = 0; i < power; i++)
            {
                result *= number;
            }
            cout << "number = " << result << endl;
            break;
    }

    return 0;
}