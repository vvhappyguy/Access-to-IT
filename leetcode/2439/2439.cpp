#include <iostream>
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
public:
    int minimizeArrayValue(vector<int>& nums)
    {
        long long sum = 0;
        long long result = 0;
        for (int index = 0; index < nums.size(); ++index)
        {
            sum += nums[index];
            result = max(result, (sum + index) / (index + 1));
        }
        return (int)result;
    }
};

int main()
{
    Solution s;
    vector<int> test = {3, 7, 1, 6};
    cout << s.minimizeArrayValue(test) << endl;
    printVector(test);
    cout << "---------------------" << endl;

    test = {10, 1};
    cout << s.minimizeArrayValue(test) << endl;
    printVector(test);
    cout << "---------------------" << endl;

    test = {13, 13, 20, 0, 8, 9, 9};
    cout << s.minimizeArrayValue(test) << endl;
    printVector(test);
    cout << "---------------------" << endl;

    test = {6, 9, 3, 8, 14};
    cout << s.minimizeArrayValue(test) << endl; // 8
    printVector(test);
    cout << "---------------------" << endl;

    return 0;
}