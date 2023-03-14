// Compile with g++ (gcc ver. 8.2.0)
// 32. Конгруэнтный метод формирования псевдослучайных чисел
// Запрограммировать генератор псевдослучайных чисел,
// используя конгруэнтный метод формирования псевдослучайных чисел.
// Input: count, x0, a, u, m (int)
// Output: count * (double)

#include <iostream>

using namespace std;

double takeOnePseudo(size_t& _x, size_t& _a, size_t& _u, size_t& _m);

int main()
{
    size_t x0 = 0;
    size_t count = 0;
    size_t a = 0;
    size_t u = 0;
    size_t m = 0;

    cout << "Please enter count of numbers to generate: ";
    cin >> count;

    cout << "Please enter start values (all must be less than `m` and more than 0)" << endl;
    cout << "`m` value: ";
    cin >> m;
    cout << "`X0` value: ";
    cin >> x0;
    cout << "`a` value: ";
    cin >> a;
    cout << "`u` value: ";
    cin >> u;

    for (size_t i = 0; i < count; i++)
    {
        cout << "Pseudo: " << i << " " << takeOnePseudo(x0, a, u, m) << endl;
    }

    return 0;
}

double takeOnePseudo(size_t& _x, size_t& _a, size_t& _u, size_t& _m)
{
    _x = (((_a * _x) + _u) % _m);
    return _x / double(_m);
}