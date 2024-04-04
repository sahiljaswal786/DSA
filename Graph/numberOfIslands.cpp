/*Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.
You may assume all four edges of the grid are all surrounded by water.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<char>> &grid, int i, int j, int m, int n,
         vector<vector<int>> &visited)
{
    visited[i][j] = 1;
    if (j - 1 >= 0 && grid[i][j - 1] == '1' && visited[i][j - 1] == 0)
    {
        dfs(grid, i, j - 1, m, n, visited);
    }
    if (i - 1 >= 0 && grid[i - 1][j] == '1' && visited[i - 1][j] == 0)
    {
        dfs(grid, i - 1, j, m, n, visited);
    }
    if (j + 1 < n && grid[i][j + 1] == '1' && visited[i][j + 1] == 0)
    {
        dfs(grid, i, j + 1, m, n, visited);
    }
    if (i + 1 < m && grid[i + 1][j] == '1' && visited[i + 1][j] == 0)
    {
        dfs(grid, i + 1, j, m, n, visited);
    }
    return;
}

int numberOfIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));
    int cnt = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1' && visited[i][j] == 0)
            {
                cnt++;
                dfs(grid, i, j, m, n, visited);
            }
        }
    }
    return cnt;
}

int main()
{
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}

    };

    cout << numberOfIslands(grid);

    return 0;
}