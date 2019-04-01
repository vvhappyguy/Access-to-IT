// Compile with g++ (gcc ver. 8.2.0)
// 3. Перевод в верхний регистр - I
// Input: n (uint), n * (float)
// Output: float

#include <iostream>

using namespace std;

int main()
{
    int count = 0;
    float sum = 0;

    cout << "Take count of numbers: ";
    cin >> count;

    float tmp = 0;
    for(int i = 0; i < count; i++)
    {    
        cin >> tmp;
        sum += tmp;
        tmp = 0;
    }

    cout << endl << "Result: " << sum / count << endl;

    return 0;
}