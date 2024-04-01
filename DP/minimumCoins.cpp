/*We are given a target sum of ‘X’ and ‘N’ distinct numbers denoting the coin denominations. 
We need to tell the minimum number of coins required to reach the target sum. 
We can pick a coin denomination for any number of times we want.*/


#include <bits/stdc++.h>
using namespace std;

int minimumCoins(int n, int amount, vector<int> &coins)
{

    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

    for (int i = 0; i <= amount; i++)
    {
        if (i % coins[0] == 0)
        {
            dp[0][i] = i / coins[0];
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            int noTaken = dp[i - 1][j];
            int Taken = 1e9;
            if (coins[i] <= amount)
                Taken = 1 + dp[i][j - coins[i]];
            dp[i][j] = min(Taken, noTaken);
        }
    }

    return dp[n - 1][amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    int n = coins.size();

    cout << minimumCoins(n , amount, coins);
}