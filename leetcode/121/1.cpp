#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums);

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        if (prices.size() == 1)
            return 0;
        int min = prices[0];
        int max = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            if (prices[i] - min > max)
            {
                max = prices[i] - min;
            }
            if (prices[i] < min)
            {
                min = prices[i];
            }
            cout << min << ' ' << max << endl;
        }
        return max;
    }
};

void printVector(vector<int>& nums)
{
    for (const auto& num : nums)
        cout << num << ' ';

    cout << endl;
}

int main()
{
    Solution s;
    vector<int> test = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(test) << endl;
    return 0;
}