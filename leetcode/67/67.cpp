#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string& big = a.size() > b.size() ? a : b;
        string& little = a.size() <= b.size() ? a : b;
        bool flag = false;
        auto it = big.rbegin();

        for (auto l = little.rbegin(); it != big.rend() && l != little.rend(); it++, l++)
        {
            if (*it == '1' && *l == '1')
            {
                if (flag)
                {
                    *it = '1';
                }
                else
                {
                    *it = '0';
                }
                flag = true;
            }
            else if (*it == '0' && *l == '1' || *it == '1' && *l == '0')
            {
                if (flag)
                {
                    *it = '0';
                    flag = true;
                }
                else
                {
                    *it = '1';
                }
            }
            else
            {
                if (flag)
                {
                    *it = '1';
                    flag = true;
                }
                else
                {
                    *it = '0';
                }
                flag = false;
            }
        }
        while (it != big.rend())
        {
            if (flag && *it == '0')
            {
                *it = '1';
                flag = false;
                break;
            }
            else if (flag && *it == '1')
            {
                *it = '0';
                flag = true;
            }

            it++;
        }
        if (flag)
        {
            big = "1" + big;
        }
        return big;
    }
};

int main()
{
    Solution s;

    string a1 = "11";
    string a2 = "1";
    cout << s.addBinary(a1, a2) << endl;

    return 0;
}