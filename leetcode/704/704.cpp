#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int>& nums, int target)
    {
        size_t start = 0;
        size_t end = nums.size() - 1;
        size_t middle = end / 2;

        while (start < end)
        {
            // cout << middle << ":" << nums[middle] << endl;
            // cin.get();
            middle = start + (end - start) / 2;
            if (nums[middle] < target)
            {
                start = middle + 1;
            }
            else
            {
                end = middle;
            }
            
        }
        if (nums[start] != target)
            return -1;
        return start;
    }
};

int main()
{
    Solution s;
    vector<int> test = {1, 2, 3, 4, 5, 6};
    int target = 3;
    cout << s.search(test, target) << endl;
    target = 4;
    cout << s.search(test, target) << endl;
    target = 0;
    cout << s.search(test, target) << endl;
    target = 7;
    cout << s.search(test, target) << endl;

    test = {1, 2, 3, 10, 11, 12};
    target = 4;
    cout << s.search(test, target) << endl;
    target = 9;
    cout << s.search(test, target) << endl;
    target = 3;
    cout << s.search(test, target) << endl;
    return 0;
}