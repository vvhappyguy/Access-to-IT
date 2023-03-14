// compiled with clang (10.0.1)
// 31. Циклическое вычисление суммы чисел
// Input: int
// Output: int

#include <iostream>
using namespace std;

int main()
{
    int lastNumber, sum = 0;
    cout << "Введите последнее число последовательности: ";
    cin >> lastNumber;
    for (int i = 5; i <= lastNumber; i += 5)
    {
        sum += i;
    }
    cout << "Сумма чисел, делящихся на 5, из последовательности [0, " << lastNumber << "] равна " << sum << endl;
    return 0;
}