#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int partitionString(string s)
    {
        unordered_set<char> set;
        int result = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (set.find(s[i]) != set.end())
            {
                set.clear();
                result++;
            }
            set.insert(s[i]);
        }
        return result;
    }
};

// from lc
class SolutionGenius
{
public:
    int partitionString(string s)
    {
        int i = 0, ans = 1, flag = 0;
        while (i < s.size())
        {
            int val = s[i] - 'a';
            if (flag & (1 << val))
            {
                flag = 0;
                ans++;
            }
            flag = flag | (1 << val);
            i++;
        }
        return ans;
    }
};

int main()
{
    Solution s;
    string test = "abacaba";
    cout << s.partitionString(test) << endl;
    cout << "---------------------" << endl;

    test = "ssssss";
    cout << s.partitionString(test) << endl;
    cout << "---------------------" << endl;

    return 0;
}