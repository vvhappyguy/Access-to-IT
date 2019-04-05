//compiled with clang (10.0.1)
//26. Таблица квадратов чисел на С++
//Input: 
//Output: 5 strings 

#include <iostream>
using namespace std;

int main()
{
    cout<<"\t\t\tТаблица квадратов чисел" << endl;
    cout<<"\t\t\t-----------------------" << endl << endl;
    cout << "Число" << "\t\t\tКвадрат числа" << endl;
    cout << "-----" << "\t\t\t-------------" << endl << endl;
    for (int i = 1; i <= 5; i++)
    {
        cout << i << "\t\t\t" << i * i << endl;
    }
    return 0;
}