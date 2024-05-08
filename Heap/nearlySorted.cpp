#include <bits/stdc++.h>
using namespace std;

vector<int> sortArray(vector<int> &nums, int k)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}

int main()
{
    vector<int> arr = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;

    vector<int> ans = sortArray(arr, k);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}