// Compile with g++ (gcc ver. 8.2.0)
// 23. Разработать функцию,
// в которую передаются в качестве аргументов массив типа float и его размер.
// Функция должна возвращать среднее арифметическое элементов массива.
// Input: n (uint), n * (float)
// Output: float

#include <iostream>

using namespace std;

float averageAr(float* _array, int _size);

int main()
{
    int count = 0;

    cout << "Take count of numbers: ";
    cin >> count;

    float* numbers = new float[count];

    for (int i = 0; i < count; i++)
    {
        cin >> numbers[i];
    }

    cout << endl << "Result: " << averageAr(numbers, count) << endl;

    delete numbers;
    return 0;
}

float averageAr(float* _array, int _size)
{
    float sum = 0;
    for (int i = 0; i < _size; i++)
    {
        sum += _array[i];
    }
    return (float)(sum / _size);
}