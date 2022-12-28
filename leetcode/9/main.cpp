#include <cassert>
#include <cstdint>
#include <iostream>

// 12:55 - 13:24

std::size_t tenCount(int x)
{
    if (x == 0)
    {
        return 1;
    }
    std::size_t tens = 1;
    while (x != 0)
    {
        x /= 10;
        tens *= 10;
    }
    tens /= 10;
    // std::cout << tens;
    return tens;
}

bool isPalindrome(int x)
{
    if (x < 0)
        return false;
    else if (x <= 0)
    {
        return true;
    }

    std::size_t tens = tenCount(x);
    while (x != 0)
    {
        int big = x / tens;
        int little = x % 10;
        std::cout << "x=" << x << "\tbig = " << big << "\tlittle = " << little << "\ttens = " << tens << std::endl;
        if (big != little)
            return false;
        x %= tens;
        x /= 10;

        tens /= 100;
    }
    return true;
}

int main()
{
    int i;
    std::cin >> i;
    std::cout << isPalindrome(i);
    return 0;
}