// Compile with g++ (gcc ver. 8.2.0)
// 3. Перевод в верхний регистр - I
// Input: char
// Output: char

#include <cctype>
#include <iostream>

using namespace std;

int main()
{
    char l;
    cin >> l;
    cout << (char)toupper(l) << endl;
    return 0;
}