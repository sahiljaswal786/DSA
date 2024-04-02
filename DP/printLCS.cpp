// printing longest common subsequence

#include <bits/stdc++.h>
using namespace std;

void longestCommonSubsequence(string text1, string text2)
{
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[n - 1] == text2[m - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    int len = dp[n][m];

    int index = len - 1;
    int i = n;
    int j = m;

    string str = "";

    for (int i = 1; i <= len; i++)
    {
        str += "$";
    }

    while (i > 0 && j > 0)
    {
        if (text1[i - 1] == text2[j - 1])
        {
            str[index] = text1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (text1[i - 1] > text2[j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    cout << str;
}

int main()
{
    string text1 = "abcde";
    string text2 = "ace";

    longestCommonSubsequence(text1, text2);
}