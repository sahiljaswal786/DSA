

#include <bits/stdc++.h>
using namespace std;

int uniquePaths( int m , int n , vector<vector<int>>& dp){
    if ( m == 0 && n == 0) return 1;
    if (m < 0 || n < 0) return 0;

    if (dp[m][n] !=-1) return dp[m][n];

    int left = uniquePaths( m , n-1, dp);
    int right = uniquePaths( m -1 , n, dp);

    return dp[m][n] = left + right;
}

int main(){
    int m = 3;
    int n = 7;
    vector<vector<int>> dp(m , vector<int> (n , -1));
    cout << uniquePaths( m-1, n-1 , dp);
}