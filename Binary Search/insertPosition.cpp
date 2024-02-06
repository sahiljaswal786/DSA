#include <bits/stdc++.h>
using namespace std;

int insert(vector<int> arr, int k){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    int ans;

    while (low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >= k){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } return ans;
}


int main(){
    vector<int> arr = {7 , 9, 12 , 17, 23, 26, 34 , 45, 56, 65};
    cout << insert(arr , 26) ;
}