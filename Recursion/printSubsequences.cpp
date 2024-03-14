#include <bits/stdc++.h>
using namespace std;

void printSubsequences(vector<int>& arr, int index, vector<int>& res, vector<vector<int>>& ans) {
    int size = arr.size();
    if (index >= size) {
        ans.push_back(res);
        return;
    }

    // Include current element
    res.push_back(arr[index]);
    printSubsequences(arr, index + 1, res, ans);

    // Exclude current element
    res.pop_back();
    printSubsequences(arr, index + 1, res, ans);
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> res;
    printSubsequences(arr, 0, res, ans);

    // Printing the subsequences
    for (auto subsequence : ans) {
        for (auto num : subsequence) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
