#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        std::stack<int> stack;
        int j = 0;
        for (auto i = 0; i < pushed.size();)
        {
            if (stack.size() > 0 && stack.top() == popped[j])
            {
                j++;
                stack.pop();
            }
            else
            {
                stack.push(pushed[i]);
                i++;
            }
        }
        if (j > popped.size())
        {
            return true;
        }
        for (int i = j; i < popped.size(); i++)
        {
            if (stack.top() == popped[i])
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    vector<int> pushed;
    vector<int> popped;

    pushed = {1, 2, 3, 4, 5};
    popped = {4, 5, 3, 2, 1};
    cout << s.validateStackSequences(pushed, popped) << endl;
    cout << "-----" << endl;

    pushed = {1, 2, 3, 4, 5};
    popped = {4, 3, 5, 1, 2};
    cout << s.validateStackSequences(pushed, popped) << endl;
    cout << "-----" << endl;

    pushed = {1, 0};
    popped = {1, 0};
    cout << s.validateStackSequences(pushed, popped) << endl;
    cout << "-----" << endl;

    return 0;
}