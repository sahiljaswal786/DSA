#include <bits/stdc++.h>
using namespace std;

void sortNumbers(vector<int> &nums)
{
    int size = nums.size();
    int low = 0;
    int middle = 0;
    int high = size - 1;

    while (middle <= high)
    {
        switch (nums[low])
        {
        case 0:
            swap(nums[low++], nums[middle++]);
        case 1:
            middle++;
        case 2:
            swap(nums[middle], nums[high--]);
        }
    }
}

int main()
{
    vector<int> nums = {2,0,2,1,1,0};
    sortNumbers(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    return 0;
}