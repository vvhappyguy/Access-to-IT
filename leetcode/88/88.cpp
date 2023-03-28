#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int>& nums);

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int firstBack = m - 1;
        int secondBack = n - 1;
        int resBack = m + n - 1;
        while (firstBack >= 0 && secondBack >= 0)
        {
            if (nums1[firstBack] > nums2[secondBack])
            {
                nums1[resBack] = nums1[firstBack];
                firstBack--;
                resBack--;
            }
            else
            {
                nums1[resBack] = nums2[secondBack];
                secondBack--;
                resBack--;
            }
        }
        while (secondBack >= 0)
        {
            nums1[resBack] = nums2[secondBack];
            secondBack--;
            resBack--;
        }
    }

    // The second variant is to push all nums2 to end of nums1 then sort (m+n)*log(m+n)
    // This solution it about n+m time compl
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
    vector<int> test1 = {1, 5, 10, 0, 0, 0};
    vector<int> test2 = {-1, 4, 15};
    s.merge(test1, 6, test2, 3);
    printVector(test1);

    return 0;
}