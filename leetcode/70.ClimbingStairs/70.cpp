#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        vector<int> vals = {1, 2};
        for(int i = 2; i < n; i++)
        {
            vals.push_back(vals[i-1] + vals[i-2]);
        }
        return vals[n-1];
    }
};

// n = 1 -> 1
// n = 2 -> 2
// n = 3 -> 3
// n = 4

int main()
{
    Solution s;
    int stairs;

    stairs = 2;
    cout << s.climbStairs(stairs) << endl;
    cout << "--------------------------------" << endl;

    stairs = 1;
    cout << s.climbStairs(stairs) << endl;
    cout << "--------------------------------" << endl;

    stairs = 3;
    cout << s.climbStairs(stairs) << endl;
    cout << "--------------------------------" << endl;

    stairs = 4;
    cout << s.climbStairs(stairs) << endl;
    cout << "--------------------------------" << endl;

    return 0;
}