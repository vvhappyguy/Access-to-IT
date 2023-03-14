// https://leetcode.com/problems/two-sum/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
    unordered_map<int, int> hashMap;
    int currentIndex = 0;
    for (const auto& num : nums)
    {
        auto it = hashMap.find(num);
        if (it != hashMap.end())
        {
            return {it->second, currentIndex};
        }
        else
        {
            hashMap[target - num] = currentIndex;
        }
        currentIndex++;
    }
    return {};
}

void printVector(const vector<int>& nums)
{
    for (auto& num : nums)
    {
        std::cout << num << " ";
    }
}

int main(int args, char* argv[])
{
    vector<int> t1 = {1, 2, 3, 4, 5, 6};
    int target;
    std::cin >> target;
    printVector(twoSum(t1, target));
}