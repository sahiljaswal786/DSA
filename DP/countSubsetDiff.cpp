/*We are given an array ‘ARR’ with N positive integers and an integer D. 
 We need to count the number of ways we can partition the given array into two subsets,
 S1 and S2 such that S1 - S2 = D and S1 is always greater than or equal to S2.*/

#include <bits/stdc++.h>
using namespace std;

int mod =(int)1e9+7;

int subsetSum (int index , int target,vector<int>& nums, vector<vector<int>>& dp ){
    if(index == 0){
        if(target == 0 && nums[0] == 0)
            return 2;
        if(target == 0 || target == nums[0])
            return 1;
        return 0;
    }

    if ( dp[index][target] != -1) return dp[index][target];

    int noTaken = subsetSum (index - 1 , target, nums , dp);
    int Taken = 0;
    if(nums[index] <= target){
        Taken = subsetSum(index - 1, target - nums[index] , nums , dp);
    }

    return dp[index][target] = (Taken + noTaken)%mod;
}

int main(){
    vector<int> nums = {5, 2, 6, 4};
    int Difference = 3;

    int n = nums.size();

    int Totalsum = 0;

    for ( int i=0; i< n; i++){
        Totalsum += nums[i];
    }

    if( Totalsum - Difference < 0) return 0;
    if ((Totalsum - Difference) % 2 == 1) return 0;

    int sum1 = (Totalsum - Difference)/2;

    vector<vector<int>> dp(n , vector<int> (sum1 + 1, -1));

    cout<< subsetSum (n-1 , sum1, nums , dp);
}

