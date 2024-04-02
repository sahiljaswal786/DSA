// longest palindromic subsequences

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(int n, int m, vector<vector<int>> &dp, string &text1,
                             string &text2)
{
    if (n < 0 || m < 0)
        return 0;

    if (dp[n][m] != -1)
        return dp[n][m];

    if (text1[n] == text2[m])
    {
        return dp[n][m] = 1 + longestCommonSubsequence(n - 1, m - 1, dp, text1, text2);
    }
    else
        return dp[n][m] = max(longestCommonSubsequence(n - 1, m, dp, text1, text2),
                              longestCommonSubsequence(n, m - 1, dp, text1, text2));
}

int main()
{
    string text1 = "zzazz";
    string text2 = text1;
    reverse(text2.begin(), text2.end());

    int n = text1.size();
    int m = text2.length();

    vector<vector<int>> dp(n, vector<int>(m, -1));

    int LPS = longestCommonSubsequence(n - 1, m - 1, dp, text1, text2);

    int ans = n - LPS;

    cout << ans;
}