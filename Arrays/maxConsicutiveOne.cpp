#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{

    int ctr = 0;
    int ans = INT_MIN;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            ctr++;
            ans = max(ans, ctr);
        }
        else
        {
            ctr = 0;
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 0, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums);
}