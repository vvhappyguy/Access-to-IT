#include <algorithm>
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
    int numRescueBoats(vector<int>& people, int limit)
    {
        sort(people.begin(), people.end());
        // printVector(people);
        int result = 0;
        int start = 0, end = people.size() - 1;
        // cout << "limit = " << limit << endl;
        while (start <= end)
        {
            // cout << "start = " << start << endl
            //     << "end = " << end << endl;
            int sum = limit;
            int elem = 2;
            if (sum - people[end] >= 0)
            {
                sum -= people[end];
                end--;
                elem--;
            }
            if (!(end >= start))
            {
                result++;
                continue;
            }
            if (sum - people[end] >= 0 && elem > 0)
            {
                sum -= people[end];
                end--;
                elem--;
            }
            if (!(end >= start))
            {
                result++;
                continue;
            }
            if (sum - people[start] >= 0 && elem > 0 && end >= start)
            {
                sum -= people[start];
                start++;
                elem--;
            }
            result++;
        }
        return result;
    }
};

int main()
{
    Solution s;

    vector<int> people = {1, 2};
    int limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;
    cout << "----------" << endl;

    people = {3, 2, 2, 1};
    limit = 3;
    cout << s.numRescueBoats(people, limit) << endl;
    cout << "----------" << endl;

    people = {3, 5, 3, 4};
    limit = 5;
    cout << s.numRescueBoats(people, limit) << endl;
    cout << "----------" << endl;

    people = {5, 5, 5, 5};
    limit = 5;
    cout << s.numRescueBoats(people, limit) << endl;
    cout << "----------" << endl;

    return 0;
}