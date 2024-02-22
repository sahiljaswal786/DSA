#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &nums){
    int size = nums.size();
    int sum = 0;
    int ans = INT_MIN;

    for(int i=0 ; i< size; i++){
        sum += nums[i];
        ans = max(ans , sum);
        if(sum < 0){
            sum = 0;
        }
    }return ans;
}


int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout <<subarraySum(nums);
}