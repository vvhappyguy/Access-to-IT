#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (int i = 1; i < m - 1; i++) {
            for (int j = 1; j < n - 1; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    bool isClosed = dfs(grid, visited, i, j);
                    if (isClosed) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
    
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if (visited[i][j]) {
            return true;
        }
        visited[i][j] = true;
        if (grid[i][j] == 1) {
            return true;
        }
        bool isClosed = true;
        isClosed &= dfs(grid, visited, i - 1, j);
        isClosed &= dfs(grid, visited, i + 1, j);
        isClosed &= dfs(grid, visited, i, j - 1);
        isClosed &= dfs(grid, visited, i, j + 1);
        return isClosed;
    }
};

int main()
{
    Solution solution;
    
    vector<vector<int>> grid = {
        {1, 1, 1, 1, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {1, 0, 1, 0, 1, 1, 1, 0},
        {1, 0, 0, 0, 0, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0}
    };
    cout << solution.closedIsland(grid) << endl;
    return 0;
}