#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums);

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        printVector(nums);
        std::sort(nums.begin(), nums.end());
        printVector(nums);
        size_t positiveCount = 0;
        size_t zeroCount = 0;
        size_t negativeCount = 0;
        int firstNegativeIndex = -1;
        int firstZeroIndex = -1;
        int firstPositiveIndex = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < 0)
            {
                if (firstNegativeIndex == -1)
                {
                    firstNegativeIndex = i;
                }
                negativeCount += 1;
            }
            else if (nums[i] > 0)
            {
                if (firstPositiveIndex == -1)
                {
                    firstPositiveIndex = i;
                }
                positiveCount += 1;
            }
            else
            {
                if (firstZeroIndex == -1)
                {
                    firstZeroIndex = i;
                }
                zeroCount += 1;
            }
        }
        if (zeroCount == 0)
        {
            if (negativeCount == 0 || positiveCount == 0)
            {
                return result;
            }
        }
        cout << "PositiveCount=" << positiveCount << endl
             << "ZeroCount=" << zeroCount << endl
             << "NegativeCount=" << negativeCount << endl
             << "FirstNegativeIndex=" << firstNegativeIndex << endl
             << "FirstZeroIndex=" << firstZeroIndex << endl
             << "FirstPositiveIndex=" << firstPositiveIndex << endl;

        return result;
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
    s.threeSum(test);
    printVector(test);
    return 0;
}