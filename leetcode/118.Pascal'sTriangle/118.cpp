#include <iostream>
#include <limits>
#include <queue>

using namespace std;

void printVectorOfVectors(const vector<vector<int>>& v)
{
    for (const auto& a : v)
    {
        for (const auto& b : a)
        {
            cout << b << " ";
        }
        cout << endl;
    }
}

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        result.push_back({1});
        if (numRows == 1)
        {
            return result;
        }
        result.push_back({1, 1});

        int rowIndex = 2;
        numRows -= 2;
        while (numRows > 0)
        {
            result.push_back(vector<int>(rowIndex + 1));
            result[rowIndex][0] = 1;
            result[rowIndex][rowIndex] = 1;
            for (int j = 1; j < rowIndex; j++)
            {
                result[rowIndex][j] = result[rowIndex - 1][j - 1] + result[rowIndex - 1][j];
            }

            rowIndex++;
            numRows--;
        }
        return result;
    }
};

int main()
{
    Solution solution;
    int rows;

    rows = 1;
    printVectorOfVectors(solution.generate(rows));
    cout << "--------------------------------" << endl;

    rows = 3;
    printVectorOfVectors(solution.generate(rows));
    cout << "--------------------------------" << endl;

    rows = 30;
    printVectorOfVectors(solution.generate(rows));
    cout << "--------------------------------" << endl;

    return 0;
}