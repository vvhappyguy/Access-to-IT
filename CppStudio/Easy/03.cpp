// Compile with g++ (gcc ver. 8.2.0)
// 23. Организовать ввод двухзначного натурального числа с клавиатуры.
// Программа должна определить наименьшую и наибольшую цифры,
// которые входят в состав данного натурального числа.
// Input: int n(9 < n < 100)
// Output: int min, int max

#include <iostream>

using namespace std;

int main()
{
    int number = 0;

    cin >> number;

    if (number < 10 || number > 99)
    {
        cout << "Bad input value. Number must be in [10,99]." << endl;
        return 1;
    }

    int first = number % 10;
    int second = number / 10;

    if (first > second)
    {
        cout << first << " bigger than " << second;
    }
    else if (second > first)
    {
        cout << second << " bigger than " << first;
    }
    else
    {
        cout << "There are equal.";
    }
    cout << endl;
    return 0;
}
