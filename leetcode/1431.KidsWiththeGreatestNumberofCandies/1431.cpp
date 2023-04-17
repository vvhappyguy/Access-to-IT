#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void print_vector(const vector<T>& v)
{
    for (const auto& e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector<bool> res(candies.size(), false);
        int maxCandies = 0;
        for (int i = 0; i < candies.size(); i++)
        {
            if (maxCandies < candies[i])
            {
                maxCandies = candies[i];
            }
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if (maxCandies <= candies[i] + extraCandies)
            {
                res[i] = true;
            }
        }
        return res;
    }
};

int main(int argc, const char* argv[])
{
    Solution solution;

    vector<int> candies;
    int extraCandies;

    candies = {2, 3, 5, 1, 3};
    extraCandies = 3;
    print_vector(solution.kidsWithCandies(candies, extraCandies));
    cout << "------" << endl;

    return 0;
}