#include <bits/stdc++.h>
using namespace std;

int maxBanans(vector<int> &piles, int n)
{
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, piles[i]);
    }
    return ans;
}

long long func(vector<int> &piles, int hourly)
{
    long long ans = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        ans += ceil((double)(piles[i]) / (double)(hourly));
    }
    return ans;
}

int minEatingSpeed(vector<int> &piles, int hours)
{
    int n = piles.size();
    long long low = 1;
    long long high = maxBanans(piles, n);
    long long res;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        long long totalHours = func(piles, mid);

        if (totalHours <= hours)
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return res;
}

int main()
{
    int hours = 8;
    vector<int> piles = {3, 6, 7, 11};
    cout << minEatingSpeed(piles, hours);
}