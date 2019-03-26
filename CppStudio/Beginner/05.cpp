// Compile with g++ (gcc ver. 8.2.0)
// 5. Преобразование значения типа int в char - I
// Input: int
// Output: value from ASCII-table in char

#include <iostream>

using namespace std;

int main()
{
    int number = 0;
    cin >> number;
    

    char a = (char)number;
    cout << a << std::endl;

    return 0;
}