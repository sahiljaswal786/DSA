#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = (low + high)/2;

        if (arr[mid] == target){
            return mid;
        } 

        else if (arr[mid] >= arr[low]){
            if(arr[low]<= target && arr[mid] >= target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if( arr[mid]<= target && arr[high]>= target){
                low = mid + 1;
            } else {
                high = low - 1;
            }
        }
    } return -1;
}



// if we have duplicate values use below function


int search2(vector<int> &arr, int target){
    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){
        int mid = (low + high)/2;

        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low = low + 1;
            high = high - 1;
        }

        if (arr[mid] == target){
            return mid;
        } 

        else if (arr[mid] >= arr[low]){
            if(arr[low]<= target && arr[mid] >= target){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } else {
            if( arr[mid]<= target && arr[high]>= target){
                low = mid + 1;
            } else {
                high = low - 1;
            }
        }
    } return -1;
}

int main(){
    vector<int> arr = {4,5,6,7,4,1,2,4};
    cout << search2(arr , 7) ;
}