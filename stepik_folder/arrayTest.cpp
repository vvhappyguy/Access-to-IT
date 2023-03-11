#include <iostream>
#include <array>

using namespace std;

int main()
{
    int b[4][4] = {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };

    array<array<int,4>,4> buffer =
    {
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4},
        {1,2,3,4}
    };


    return 0;
}