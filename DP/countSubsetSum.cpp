#include <bits/stdc++.h>
using namespace std;

int subsetSum (int index , int target,vector<int>& nums, vector<vector<int>>& dp ){
    if ( target == 0){
        return 1;
    }

    if ( index == 0 ){
        return (nums[0] == target) ? 1 : 0;
    }

    if ( dp[index][target] != -1) return dp[index][target];

    int noTaken = subsetSum (index - 1 , target, nums , dp);
    int Taken = 0;
    if(nums[index] <= target){
        Taken = subsetSum(index - 1, target - nums[index] , nums , dp);
    }

    return dp[index][target] = Taken + noTaken;
}

int main(){
    vector<int> nums = {1, 2, 2, 3};
    int target = 3;

    int n = nums.size();

    vector<vector<int>> dp(n , vector<int> (target+1, -1));

    cout<< subsetSum (n-1 , target, nums , dp);
}