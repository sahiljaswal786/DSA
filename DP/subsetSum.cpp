#include <bits/stdc++.h>
using namespace std;

bool subsetSum (vector<int>& arr, int index , int target, vector<vector<int>>& dp){
    if (target == 0) return true;
    if (index == 0) return arr[0] == target;

    if (dp[index][target] != -1) return dp[index][target];

    bool noTake = subsetSum (arr , index - 1, target, dp);
    bool Take = false;
    if (target >= arr[index])
        Take = subsetSum (arr , index - 1, target - arr[index], dp);
    
    return dp[index][target] = Take || noTake ;
}


int main(){
    vector<int> arr = {1, 3, 7, 8, 10};
    int sum = 11;
    int n = arr.size();

    vector<vector<int>> dp(n , vector<int>(sum + 1, -1));

    if(subsetSum(arr, n-1, sum, dp)){
        cout << "Subset with the given target found";
    } else {
        cout << "Subset with the given target not found";
    }

    return 0;
}