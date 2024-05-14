#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int low , int mid, int high){
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &nums, int low , int high){
    if ( low == high) return;

    int mid = (low + high)/2;

    mergeSort(nums, low , mid );
    mergeSort(nums, mid + 1, high);

    merge(nums, low , mid , high);
    
}

int main(){
    vector<int> nums = {4, 2, 1, 6, 7};

    int low = 0;
    int high = nums.size() - 1;

    mergeSort(nums, low , high);

    for (int i = 0; i < nums.size(); i++){
        cout << nums[i] << " ";
    }
}