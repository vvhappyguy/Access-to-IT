// Compile with g++ (gcc ver. 8.2.0)
// 2. Алгебраическая сумма 1^k + 2^k + 3^k + ... + N^k
// Найти алгебраическую сумму для выражения: 1^k + 2^k + 3^k + … + N^k. 
// N и степень k вводит пользователь. 
// Input: n, k
// Output: sum


#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    size_t N = 0;
    size_t k = 1;

    size_t sum = 0;

    cout << "Enter N: ";
    cin >> N;
    cout << "Enter k: ";
    cin >> k;

    for(size_t i = 1; i <= N; i++)
    {
        sum += pow(i,k);
    }

    cout << "Sum = " << sum << endl;

    return 0;
}