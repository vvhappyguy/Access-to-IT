#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums)
{
    cout << nums.size() << ":[ ";
    for (auto n : nums)
    {
        cout << n << ", ";
    }
    cout << endl;
}

bool canJump(vector<int>& nums)
{
    static int count = 0;
    if (nums.size() == 1)
    {
        return true;
    }
    if (nums[0] >= nums.size() - 1)
    {
        return true;
    }
    for (int i = nums[0]; i >= 1; i--)
    {
        if (nums[i] == 0)
        {
            continue;
        }
        vector<int> tmp(nums.begin() + i, nums.end());
        count++;
        if (canJump(tmp))
        {
            return true;
        }
    }
    cout << "Count: " << count << endl;
    return false;
}

bool canJump(vector<int>& nums)
{
    // keep track of the maximum index that can be reached
    int max_index = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        // if the current index is greater than the maximum index that can be reached, return False
        if (i > max_index)
        {
            return false;
        }
        // update the maximum index that can be reached
        max_index = max(max_index, i + nums[i]);
    }
    // if the loop finishes, it means the last index is reachable
    return true;
}

int main()
{
    vector<int> test1 = {2, 3, 1, 1, 4};
    std::cout << canJump(test1) << std::endl;

    test1 = {3, 2, 1, 0, 4};
    std::cout << canJump(test1) << std::endl;

    test1 = {0};
    std::cout << canJump(test1) << std::endl;

    test1 = {2, 0, 6, 9, 8, 4, 5, 0, 8, 9, 1, 2, 9, 6, 8, 8, 0, 6, 3, 1, 2, 2, 1, 2, 6, 5, 3, 1, 2, 2, 6, 4, 2, 4, 3,
             0, 0, 0, 3, 8, 2, 4, 0, 1, 2, 0, 1, 4, 6, 5, 8, 0, 7, 9, 3, 4, 6, 6, 5, 8, 9, 3, 4, 3, 7, 0, 4, 9, 0, 9,
             8, 4, 3, 0, 7, 7, 1, 9, 1, 9, 4, 9, 0, 1, 9, 5, 7, 7, 1, 5, 8, 2, 8, 2, 6, 8, 2, 2, 7, 5, 1, 7, 9, 6};
    std::cout << canJump(test1) << std::endl;
    return 0;
}