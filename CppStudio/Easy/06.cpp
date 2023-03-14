// compiled with clang (10.0.1)
// 6. Выбор дня недели оператором switch
// Input: int
// Output: string

#include <iostream>
using namespace std;

int main()
{
    int number;
    cout << "1. Понедельник\n2. Вторник\n3. Среда\n4. Четверг\n5. Пятница\n6. Суббота\n7. Воскресенье\n";
    cout << "Введите номер: ";
    cin >> number;
    switch (number)
    {
        case 1:
            cout << "Понедельник" << endl;
            break;
        case 2:
            cout << "Вторник" << endl;
            break;
        case 3:
            cout << "Среда" << endl;
            break;
        case 4:
            cout << "Четверг" << endl;
            break;
        case 5:
            cout << "Пятница" << endl;
            break;
        case 6:
            cout << "Суббота" << endl;
            break;
        case 7:
            cout << "Воскресенье" << endl;
            break;
        default:
            cout << "Введите цифру в диапазоне от 1 до 7" << endl;
            break;
    }
    return 0;
}