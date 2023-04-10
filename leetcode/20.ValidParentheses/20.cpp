#include <iostream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution
{
    std::map<char, char> m = {
  //{'{', '}'},
        {'}', '{'},
 //{'(', ')'},
        {')', '('},
 //{'[', ']'},
        {']', '['}
    };

public:
    bool isValid(string s)
    {
        stack<char> st;
        for (auto c : s)
        {

            if (!st.empty() && st.top() == m[c])
            {
                st.pop();
            }
            else
            {
                st.push(c);
            }
        }
        // cout << st.size() << endl;
        return st.empty();
    }

    bool isValidOld(string s)
    {
        if (s.length() % 2 != 0)
            return false;
        std::stack<char> symbols;
        symbols.push(s[0]);
        for (int i = 1; i < s.length(); ++i)
        {
            if (symbols.empty())
            {
                symbols.push(s[i]);
                continue;
            }

            bool st = (s[i] == ')' && symbols.top() == '(' || s[i] == ']' && symbols.top() == '[' ||
                       s[i] == '}' && symbols.top() == '{');
            if (st)
            {
                symbols.pop();
            }
            else
                symbols.push(s[i]);
        }
        return symbols.empty();
    }
};

int main()
{
    Solution s;
    cout << s.isValid("{()}") << endl;             // 1
    cout << s.isValid("({})}") << endl;            // 0
    cout << s.isValid("({}({}))") << endl;         // 1
    cout << s.isValid("({}({}({})))") << endl;     // 1
    cout << s.isValid("({}({}({}({}))))") << endl; // 1
    cout << s.isValid("({}({}({}({}({}))))({}))") << endl;
    cout << s.isValid("(){}}{") << endl; // 0
    return 0;
}