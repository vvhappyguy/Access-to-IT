#include <iostream>
#include <limits>
#include <queue>
#include <string>

using namespace std;

class Solution
{
public:
    int32_t reverse(int x)
    {
        int flag = 1;
        if (x < 0)
            flag = -1;
        queue<int> number;
        while (x != 0)
        {
            number.push(x % 10);
            x /= 10;
        }

        int64_t result = 0;
        while (!number.empty())
        {
            result *= 10;
            result += number.front();
            number.pop();
        }
        if (result > std::numeric_limits<int32_t>::max() || result < std::numeric_limits<int32_t>::min())
        {
            return 0;
        }
        return result;
    }

    int reverseBetter(int x)
    {
        long r = 0;
        while (x)
        {
            r = (r * 10) + (x % 10);
            x = x / 10;
        }
        if (r > INT_MAX || r < INT_MIN)
            return 0;
        return int(r);
    }
};

int main()
{
    Solution s;
    cout << s.reverse(123) << endl;

    cout << s.reverse(1234) << endl;

    cout << s.reverse(10) << endl;

    cout << s.reverse(-12) << endl;

    cout << s.reverse(200) << endl;

    cout << s.reverse(2020) << endl;

    cout << s.reverse(1534236469) << endl;

    cout << s.reverse(-2147483648) << endl;

    return 0;
}