#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstring(string& text1, string& text2){
    int n = text1.size();
    int m = text2.size();

    vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }

    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                int val = 1 + dp[i - 1][j - 1];
                dp[i][j] = val;
                ans = max(ans , dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    } return ans;
}


int main(){

    string text1 = "abcjklp";
    string text2 = "abcje";

    cout << longestCommonSubstring (text1 , text2);
}