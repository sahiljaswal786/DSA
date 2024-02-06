#include <bits/stdc++.h>>
using namespace std;

int binary_search(vector<int>& arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;

    while(low <= high){
        int mid = (low + high) / 2;
        if (arr[mid] == target){
            return mid;
        } else if (arr[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    } return -1;
}

int main(){
    vector<int> arr = {7 , 9, 12 , 17, 23, 26, 34 , 45, 56, 65};
    cout << binary_search(arr , 26) ;
}