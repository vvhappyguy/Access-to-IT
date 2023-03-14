#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums);

class Solution
{
public:
    int minimumDeviation(vector<int>& nums)
    {
        printVector(nums);
        int maxOdd = 1;
        for (const auto& num : nums)
        {
            if (num % 2 != 0 && maxOdd < num)
            {
                maxOdd = num;
            }
        }
        printVector(nums);
        int min = maxOdd;
        for (auto& num : nums)
        {
            // if(num % 2 != 0 && num != maxOdd && (num * 2 - maxOdd < maxOdd - num))
            if (num % 2 != 0 && num != maxOdd && (num * 2 < maxOdd))
            {
                num *= 2;
            }
            else
            {
                while ((num % 2 == 0) && (abs(maxOdd - num / 2) <= abs(num - maxOdd)))
                {
                    num /= 2;
                }
            }
            if (min > num)
            {
                min = num;
            }
            if (num > maxOdd)
            {
                maxOdd = num;
            }
        }
        printVector(nums);

        return maxOdd - min;
    }
    // int minimumDeviation(vector<int>& nums) {
    //     printVector(nums);
    //     int max = 0;
    //     for(auto& num: nums)
    //     {
    //         while(num % 2 == 0)
    //         {
    //             num /= 2;
    //         }
    //         if(max < num)
    //         {
    //             max = num;
    //         }
    //     }
    //     printVector(nums);
    //     int min = max;
    //     for(auto& num: nums)
    //     {
    //         while(max > num * 2 && num % 2 != 0)
    //         {
    //             num *= 2;
    //         }
    //         if((num * 2 - max < max - num) && num % 2 != 0)
    //         {
    //             num *= 2;
    //         }
    //         if(min > num)
    //         {
    //             min = num;
    //         }
    //         if(max < num)
    //         {
    //             max = num;
    //         }
    //     }
    //     printVector(nums);
    //     cout << min << ' ' << max << endl;
    //     return max - min;
    // }
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
    // vector<int> test = {4,1,5,20,3};
    // vector<int> test = {1, 2, 3, 4};
    vector<int> test = {2, 10, 8};
    // {4,1,5,20,3};
    // {4,1,5,10,3};
    // {4,1,5,5,3};
    // {4,2,5,5,3};
    // {4,4,5,5,3};
    // printVector(test);
    cout << s.minimumDeviation(test) << endl;
    // printVector(test);
    return 0;
}