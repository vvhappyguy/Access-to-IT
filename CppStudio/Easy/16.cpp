// Compile with g++ (gcc ver. 8.2.0)
// 23. Печать ромба символами ASCII
// Составить программу, которая будет печатать ромб одним из значков (* или + или #)
// Выбор значков организовать оператором switch.
// Input: n (1,2,3 choose symbol), h (int height)
// Output: console picture

#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    int h, b, i, s, a, number;
    char r;
    s = 0;

    cout << "Введите 1 для печати ромба \"*\"" << endl;
    cout << "Введите 2 для печати ромба \"+\"" << endl;
    cout << "Введите 3 для печати ромба \"#\"" << endl;
    cout << "Пожалуйста введите число от 1-3: ";
    cin >> number;
    cout << endl;

    switch (number)
    {
        case 1:
        {
            r = '*';
            break;
        }
        case 2:
        {
            r = '+';
            break;
        }
        case 3:
        {
            r = '#';
            break;
        }
        default:
            cout << "Неправильный ввод" << endl;
            return 1;
    }

    cout << "Вводить нужно только положительные нечетные числа.\n\n";
    cout << "высота ромба: ";
    cin >> h;
    cout << "ширина ромба: ";
    cin >> a;
    cout << endl;

    for (i = 1; i <= h; i++)
    {
        for (b = 1; b <= a; b++)
        {
            if (b == (a / 2 + 1 - s) || b == (a / 2 + 1 + s))
            {
                cout << r;
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        if (i < h / 2 + 1)
        {
            s++;
        }
        else
        {
            s--;
        }
    }
}