// compiled with clang (10.0.1)
// 28. Точки пересечений линий
// Input: 5 floats
// Output: string

#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    float a, b, c, d, k, crossPoint1, crossPoint2, discr;

    cout << "Введите коэффициенты функции ax^2 + bx + c: " << endl;
    cout << "Коэффициент a: ";
    cin >> a;
    cout << "Коэффициент b: ";
    cin >> b;
    cout << "Коэффициент c: ";
    cin >> c;
    cout << "Введите коэффициенты функции kx + d: " << endl;
    cout << "Коэффициент k: ";
    cin >> k;
    cout << "Коэффициент d: ";
    cin >> d;
    discr = pow(b - k, 2) - 4 * a * (c - d);
    crossPoint1 = (-(b - k) + sqrt(pow(b - k, 2) - 4 * a * (c - d))) / (2 * a);
    crossPoint2 = (-(b - k) - sqrt(pow(b - k, 2) - 4 * a * (c - d))) / (2 * a);
    switch (discr > 0 ? 1 : discr == 0 ? 2 : 3)
    {
        case 1:
            cout << "Функции пересекаются в точках: ";
            cout << "[ " << crossPoint1 << ", " << k * crossPoint1 + d << " ]";
            cout << " [ " << crossPoint2 << ", " << k * crossPoint2 + d << " ]" << endl;
            break;
        case 2:
            cout << "Функции пересекаются в точке: ";
            cout << "[ " << crossPoint1 << ", " << k * crossPoint1 + d << " ]" << endl;
            break;
        case 3:
            cout << "Функции не пересекаются" << endl;
    }
    return 0;
}