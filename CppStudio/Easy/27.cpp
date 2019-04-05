//compiled with clang (10.0.1)
//27. Таблица умножения введенного числа
//Input: int 
//Output: 10 strings

#include <iostream> 
using namespace std;

int main()
{
    int number;
    cout << "Введите целое число: ";
    cin >> number;
    cout<<"\t\t\t\t\tТаблица умножения введенного числа" << endl;
    cout<<"\t\t\t\t\t----------------------------------" << endl;
    for(int i = 1; i <= 10; i++)
    {
        cout << i << " * " << number << " = " << i * number << endl;
    }
    return 0;
}