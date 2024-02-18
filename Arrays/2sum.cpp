#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    map<int, int> mpp;
    for (int i = 0; i < nums.size(); i++)
    {
        int remaining = target - nums[i];
        if (mpp.find(remaining) != mpp.end())
        {
            ans.push_back(i);
            ans.push_back(mpp[remaining]);
        }
        mpp[nums[i]] = i;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    vector<int> res = twoSum(nums, target);

    vector<int> result = twoSum(nums, target);
    
    if (!result.empty())
    {
        cout << "Indices of the two numbers: " << result[0] << " and " << result[1] << endl;
    }
    else
    {
        cout << "No solution found." << endl;
    }
    return 0;
}