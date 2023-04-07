#include <iostream>
#include <vector>

using namespace std;

class Solution
{
    int countLands(const vector<vector<int>>& grid)
    {
        int ans = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    ans++;
                }
            }
        }
        return ans;
    }

public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        int landsCount = countLands(grid);
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, 0, landsCount);
        }
        for (int i = 0; i < m; i++)
        {
            dfs(grid, i, n - 1, landsCount);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(grid, 0, i, landsCount);
        }
        for (int i = 0; i < n; i++)
        {
            dfs(grid, m - 1, i, landsCount);
        }
        return landsCount;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& result)
    {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n)
        {
            return;
        }

        if (grid[i][j] == 1)
        {
            result--;
            grid[i][j] = 0;
        }
        else
        {
            return;
        }
        dfs(grid, i - 1, j, result);
        dfs(grid, i + 1, j, result);
        dfs(grid, i, j - 1, result);
        dfs(grid, i, j + 1, result);
    }
};

int main()
{
    Solution solution;

    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };
    cout << solution.numEnclaves(grid) << endl;
    cout << "--------------------" << endl;
    grid = {
        {0, 1, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 0}
    };
    cout << solution.numEnclaves(grid) << endl;
    return 0;
}