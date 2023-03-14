#include <stack>
#include <string>

using namespace std;

bool isValid(string s)
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