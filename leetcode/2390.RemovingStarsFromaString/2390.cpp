#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string removeStars(string s)
    {
        string result;
        int countSkip = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            if (s[i] == '*')
            {
                countSkip++;
            }
            else if (countSkip > 0)
            {
                countSkip--;
            }
            else
            {
                result += s[i];
            }
        }
        // cout << result << endl;
        if (result.length() > 0)

            for (int i = 0; i < result.length() / 2; i++)
            {
                char tmp = result[i];
                result[i] = result[result.length() - 1 - i];
                result[result.length() - 1 - i] = tmp;
            }
        return result;
    }
};

int main(int argc, const char* argv[])
{
    Solution s;
    cout << s.removeStars("leet**cod*e") << endl;
    cout << "--------------------------------" << endl;
    cout << s.removeStars("erase*****") << endl;
    cout << "--------------------------------" << endl;
    cout << s.removeStars("asfdsf") << endl;
}
