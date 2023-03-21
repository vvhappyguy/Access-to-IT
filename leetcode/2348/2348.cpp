#include <iostream>
#include <vector>

using namespace std;

long long sumSeq(size_t num)
{
    return ((num + 1) * num) / 2;
}

long long zeroFilledSubarray(vector<int>& nums)
{
    size_t j = 0;
    bool isZero = false;
    long long sum = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
        {
            isZero = true;
            j++;
        }
        else if (isZero && nums[i] != 0)
        {
            isZero = false;
            // cout << j << endl;
            // cin.get();
            sum += sumSeq(j);
            j = 0;
        }
    }
    if (isZero)
    {
        sum += sumSeq(j);
    }
    return sum;
}

long long zeroFilledSubarrayImpr(vector<int>& nums)
{
    size_t j = 0;
    long long sum = 0;
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (nums[i] == 0)
        {
            j++;
            sum += j;
            
        }
    }

    return sum;
}

int main()
{
    vector<int> collection;
    cout << zeroFilledSubarrayImpr(collection) << endl;
    collection = {0}; // 1
    cout << zeroFilledSubarrayImpr(collection) << endl;
    collection = {0, 0}; // 3
    cout << zeroFilledSubarrayImpr(collection) << endl;
    collection = {0, 0, 0}; // 6
    cout << zeroFilledSubarrayImpr(collection) << endl;
    collection = {0, 0, 0, 0}; // 10
    cout << zeroFilledSubarrayImpr(collection) << endl;
    collection = {0, 1, 0}; // 2
    cout << zeroFilledSubarrayImpr(collection) << endl;
    collection = {1, 0, 0, 1, 0, 1}; // 4
    cout << zeroFilledSubarrayImpr(collection) << endl;
    return 0;
}