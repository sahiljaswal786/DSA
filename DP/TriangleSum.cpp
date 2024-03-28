/*Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally,
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.*/

#include <bits/stdc++.h>
using namespace std;

int minimumSumPath(vector<vector<int>> &triangle, vector<vector<int>> &dp, int i, int j, int n)
{
    if (i == n - 1)
        return triangle[i][j];

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = triangle[i][j] + minimumSumPath(triangle, dp, i + 1, j, n);
    int diagonal = triangle[i][j] + minimumSumPath(triangle, dp, i + 1, j + 1, n);

    return dp[i][j] = min(down, diagonal);
}

int main()
{
    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << minimumSumPath(triangle, dp, 0, 0, n);
}
