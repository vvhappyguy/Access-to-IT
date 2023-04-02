#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

void printVector(vector<int>& nums)
{
    for (const auto& num : nums)
        cout << num << ' ';

    cout << endl;
}

class Solution
{
    int search(vector<int>& nums, long long target)
    {
        size_t start = 0;
        size_t end = nums.size() - 1;
        size_t middle = end / 2;

        if (target < nums[start])
        {
            return nums.size();
        }
        if (target > nums[end])
        {
            return 0;
        }

        while (start < end)
        {
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
        if (nums[end] < target)
            return 0;
        return nums.size() - start;
    }

public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> result(spells.size());

        sort(potions.begin(), potions.end());
        //cout << "min = " << potions[0] << " max = " << potions[potions.size() - 1] << endl;
        std::map<int, int> memory;
        for (size_t i = 0; i < spells.size(); i++)
        {
            if(spells[i] >= success)
            {
               result[i] = potions.size();
               continue;
            }
            long long val = success / spells[i];
            val += (success % spells[i] != 0);
            // cout << spells[i] << ":" << val << " mem=" << memory.count(val) << endl;
            if (memory.count(val) > 0)
            {
                result[i] = memory[val];
                // cout << "mem" << endl;
                continue;
            }
            //cout << val << ' ' << search(potions, val) << endl;
            result[i] = search(potions, val);
            memory[val] = result[i];
        }
        return result;
    }
};

int main()
{
    Solution s;
    vector<int> spells = {5, 1, 3};
    vector<int> potions = {1, 2, 3, 4, 5};
    long long success = 7;
    vector<int> res = s.successfulPairs(spells, potions, success);
    printVector(res); // [4,0,3]
    cout << "----------" << endl;
    spells = {3, 1, 2};
    potions = {8, 5, 8};
    success = 16;
    res = s.successfulPairs(spells, potions, success);
    printVector(res); // [2,0,2]
    cout << "----------" << endl;
    spells = {1, 3, 5, 8, 10, 11, 14, 16, 20};
    potions = {1, 4, 4, 4, 8};
    success = 16;
    res = s.successfulPairs(spells, potions, success);
    printVector(res); // [2,0,2]
    cout << "----------" << endl;
    spells = {1};
    potions = {45,99999};
    success = 2966799365;
    res = s.successfulPairs(spells, potions, success);
    printVector(res);
    return 0;
}