#include <bits/stdc++.h>
using namespace std;

int func(int mid, int number, int nth_Root)
{
    int ans = 1;
    for (int i = 1; i <= nth_Root; i++)
    {
        ans = ans * mid;
        if (ans > number)
            return 2;
    }
    if (ans == number)
        return 1;
    else
        return 0;
}

int nthRoot(int nth_Root, int number)
{
    int low = 1;
    int high = number;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int newMid = func(mid, number, nth_Root);

        if (newMid == 1)
            return mid;
        else if (newMid == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int nth_Root;
    int number;
    cin >> nth_Root;
    cin >> number;
    cout << nthRoot(nth_Root, number);
}