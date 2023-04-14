#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        string rev(s);
        std::reverse(rev.begin(), rev.end());
        size_t size = s.size() + 1;
        int res = 0;
        vector<vector<int>> levels(size, vector<int>(size));
        for (int i = 1; i < size; ++i)
        {
            levels[i][i] = 1;
            for (int j = 1; j < size; ++j)
            {
                if (s[i - 1] == rev[j - 1])
                {
                    levels[i][j] = levels[i - 1][j - 1] + 1;
                }
                else
                {
                    levels[i][j] = max(levels[i - 1][j], levels[i][j - 1]);
                }

                if (levels[i][j] > res)
                {
                    res = levels[i][j];
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str;

    str = "bbbab";
    cout << s.longestPalindromeSubseq(str) << endl;
    cout << "--------------------------------" << endl;

    str = "cbbd";
    cout << s.longestPalindromeSubseq(str) << endl;
    cout << "--------------------------------" << endl;

    str = "a";
    cout << s.longestPalindromeSubseq(str) << endl;
    cout << "--------------------------------" << endl;

    str = "aa";
    cout << s.longestPalindromeSubseq(str) << endl;
    cout << "--------------------------------" << endl;

    return 0;
}