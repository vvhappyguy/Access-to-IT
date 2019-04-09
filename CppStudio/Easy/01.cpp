// Compile with g++ (gcc ver. 8.2.0)
// 1. Алгебраическая сумма
// Найти Y, если Y = X1 + X2 + … + Xn,   X = Z^3 - B + A^2 / tg^2?. 
// Количество X вводятся пользователем программы. 
// Для каждого X значения Z, B, А, ? разные (вводятся пользователем программы).
// Input: count, count * (z, b, a, ?)
// Output: (float) y

#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    size_t count = 0;

    cin >> count;

    float* z = new float;
    float* b = new float;
    float* a = new float;
    float* angle = new float;
    float* x_array = new float[count];
    float* y = new float;

    for(size_t i = 0; i < count; i++)
    {
        cout << "Enter z, b, a, angle values: ";
        cin >> *z >> *b >> *a >> *angle;
        x_array[i] = pow(*z, 3) + pow(*a / tan(*angle),2) - *b;
        *y += x_array[i];
    }

    cout << "Y = sum(x_array) = " << *y << endl;

    delete b;
    delete a;
    delete angle;
    delete y;
    delete []x_array;

    return 0;
}