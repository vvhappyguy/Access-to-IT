//compiled with clang (10.0.1)
//19. Программа палиндром в С++
//Input: int n , float * n 
//Output: float

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    float sum;
    cout << "Введите количество элементов в массиве: ";
    cin >> n; 
    float *massNumber = new float[n];
    cout << "Введите сами элменты: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " элемент: ";
        cin >> massNumber[i];
        if(fabs(massNumber[i] > 2.5))
        {
            sum += massNumber[i];
        }
    }
    cout << "Сумма чисел равна " << sum << endl;

    return 0;
}