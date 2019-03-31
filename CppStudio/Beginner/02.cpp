// Compile with g++ (gcc ver. 8.2.0)
// 1. Запрограммировать математическое выражение в С++ - I
// Запрограммировать следующее выражение: (а + b — f / а) + f * a * a — (a + b) 
// Числа а, b, f вводятся с клавиатуры. 
// Организовать пользовательский интерфейс, таким образом, чтобы было понятно, в каком порядке должны вводиться числа.
// Input: int , int , int
// Output: int
#include <iostream>

using namespace std;

int main()
{
    int a=0,
        b=0,
        f =0;

    cout << "Put a, b, f:" << endl;
    cin >> a >> b >> f;

    if(a == 0)
    {
        cout << "Invalid a value. It can't be 0. Program exits." << endl;
        return 1;
    }

    cout << "Calculating (а + b — f / а) + f * a * a — (a + b) ..." << endl
        << (a + b - f / a) + f * a * a - (a + b) << endl;
    return 0;
}
