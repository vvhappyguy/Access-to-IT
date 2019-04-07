#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    size_t count = 0;

    cin >> count;

    float* z = new float;
    float* b = new float;
    float* a = new float;
    float* angle = new float;
    float* x_array = new float[count];
    float* y = new float;

    for(size_t i = 0; i < count; i++)
    {
        cout << "Enter z, b, a, angle values: ";
        cin >> *z >> *b >> *a >> *angle;
        x_array[i] = pow(*z, 3) + pow(*a / tan(*angle),2) - *b;
        *y += x_array[i];
    }

    cout << "Y = sum(x_array) = " << *y << endl;

    delete b;
    delete a;
    delete angle;
    delete y;
    delete []x_array;

    return 0;
}