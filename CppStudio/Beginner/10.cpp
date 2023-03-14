// compiled with clang (10.0.1)
// 10. Увеличение переменных с оператором if
// Input: 3 ints
// Output: 3 ints

#include <iostream>
using namespace std;

int main()
{
    int num1, num2, num3;
    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;
    cout << "Введите третье число: ";
    cin >> num3;
    if ((num1 == num2) || (num1 == num3) || (num2 == num3))
    {
        cout << "1 число = " << num1 + 5 << endl;
        cout << "2 число = " << num2 + 5 << endl;
        cout << "3 число = " << num3 + 5 << endl;
    }
    else
    {
        cout << "Равных чисел нет" << endl;
    }
    return 0;
}
