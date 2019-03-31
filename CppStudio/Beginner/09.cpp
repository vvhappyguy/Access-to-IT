//compiled with clang (10.0.1)
//9. Сравнение чисел используя оператор ветвления
//Input: 2 ints
//Output: string

#include <iostream>
using namespace std;

int main()
{
    int num1, num2;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    if (num1 > num2)
    {
        cout << "БОЛЬШЕ" << endl;
    }
    else if (num1 < num2)
    {
        cout << "МЕНЬШЕ" << endl;
    }
    else
    {
        cout << "Эти числа равны" << endl;
    }
    return 0;
}