#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        size_t i = 0;
        size_t j = s.size() - 1;
        while (i < j)
        {
            // cout << i << " " << j << endl;
            if (!isalnum(s[i]))
            {
                i++;
                continue;
            }
            if (!isalnum(s[j]))
            {
                j--;
                continue;
            }
            if (toupper(s[i]) != toupper(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string str;

    str = "A man, a plan, a canal: Panama";
    cout << s.isPalindrome(str) << endl;
    cout << "-----" << endl;

    str = "race a car";
    cout << s.isPalindrome(str) << endl;
    cout << "-----" << endl;

    str = " ";
    cout << s.isPalindrome(str) << endl;
    cout << "-----" << endl;

    str = "0P";
    cout << s.isPalindrome(str) << endl;
    cout << "-----" << endl;

    return 0;
}