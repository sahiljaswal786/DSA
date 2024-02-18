#include <bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int> &nums, int target){
    int ans = INT_MIN;
    map<int , int> mpp;
    int sum = 0;
    for(int i=0; i < nums.size(); i++){
        sum += nums[i];

        if ( sum == target ){
            ans = max(ans , i + 1);
        }

        int remaining = target - sum;

        if (mpp.find(remaining) != mpp.end()){
            ans = max(ans , i - nums[remaining]);
        }

        if (mpp.find(sum) == mpp.end()){
            nums[remaining] = i;
        }
    } return ans;
}

int main()
{
    vector<int> nums = {2,3,5,1,9};
    int target = 10;
    cout << longestSubarray(nums , target);
}