/*There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int start_node, vector<int> &visited, vector<int> adjLs[])
{
    visited[start_node] = 1;
    for (auto it : adjLs[start_node])
    {
        if (visited[it] != 1)
        {
            visited[it] = 1;
            dfs(it, visited, adjLs);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();

    vector<int> adjLs[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (isConnected[i][j] == 1 && i != j)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }

    vector<int> visited(n, 0);
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            cnt++;
            dfs(i, visited, adjLs);
        }
    }
    return cnt;
}

int main()
{
    vector<vector<int>> isConnected = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};

    cout<< findCircleNum(isConnected);
    return 0;
}