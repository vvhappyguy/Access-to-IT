#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

void printVector(vector<int>& nums);

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = strs[0];
        for(int i = 1; i < strs.size(); ++i)
        {
            if(result.length() > strs[i].length)
            {
                result = string(result.begin(), result.begin() + strs[i].length() - 1);
            }
            for(int j = 0; j < strs[i].length(); ++j)
            {
                if(result[j] != strs[i][j])
                {
                    result = string(strs[i].begin(),strs[i].begin()+j);
                    break;
                }
            }
        }
        return result;
    }
};

void printVector(vector<int>& nums)
{
    for(const auto& num: nums)
        cout << num << ' ';

    cout << endl;
}

int main()
{
    Solution s;
    vector<int> test = {7,1,5,3,6,4};
    cout << s.maxProfit(test) << endl;
    return 0;
}