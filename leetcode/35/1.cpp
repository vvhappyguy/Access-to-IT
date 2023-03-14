#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums);

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int first = 0, last = nums.size() - 1, current = (last - first) / 2 + first;
        cout << first << ' ' << current << ' ' << last << endl;
        while (first != last)
        {
            if (nums[current] < target)
            {
                first = current + 1;
                // current += current / 2;
            }
            else if (nums[current] > target)
            {
                last = current;
                // current /= 2;
            }
            else
            {
                return current;
            }
            current = (last - first) / 2 + first;
            cout << first << ' ' << current << ' ' << last << endl;
            cin.get();
        }
        cout << "Pounce!" << endl;
        if (nums[first] > target)
        {
            current = first;
        }
        else if (nums[first] < target)
        {
            current = first + 1;
        }
        else
        {
            current = first;
        }

        return current;
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
    vector<int> test = {1, 3, 5, 7, 9, 11};
    // vector<int> test = {1,3};
    // cout << s.searchInsert(test, 4) << endl;
    for (int i = 0; i < 13; i++)
        cout << "Answer: " << i << ' ' << endl << s.searchInsert(test, i) << endl;
    return 0;
}