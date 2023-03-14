// Compile with g++ (gcc ver. 8.2.0)
// 30. Используя оператор цикла do while,
// составить программу, которая будет требовать ввод цифр с клавиатуры до тех пор,
// пока не будет введена цифра 1.
// Input: int * n (n is unknown)
// Output: no data

#include <iostream>

using namespace std;

int main()
{
    int number = 0;

    do
    {
        cout << "Put number (1 to exit): ";
        cin >> number;
    } while (number != 1);

    return 0;
}