/*You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing 
each of them is that adjacent houses have security systems connected and 
it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, 
return the maximum amount of money you can rob tonight without alerting the police.*/

#include <bits/stdc++.h>
using namespace std;

int houseRobber(vector<int>& nums, int n , vector<int>& dp){
    if ( n == 0 ) return nums[0];
    if( n < 0 ) return 0;
    if (dp[n] != -1) return dp[n];

    int pick = nums[n] + houseRobber( nums , n-2 , dp);
    int notpick = 0 + houseRobber( nums , n-1 , dp);

    return dp[n] = max (pick, notpick);
}

int main(){
    vector<int> nums = {2,7,9,3,1};
    int n = nums.size();
    vector<int> dp(n , -1);
    cout << houseRobber(nums , n-1 , dp);
}