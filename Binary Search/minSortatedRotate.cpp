#include <bits/stdc++.h>
using namespace std;

int minimum_element (vector<int> &arr){
    int low = 0;
    int high = arr.size() - 1;
    int ans = INT_MAX;

    while( low <= high){
        int mid = (low + high)/2;
        
        if( arr[low] <= arr[high]){
            ans = min ( ans , arr[low]);
        }

        if(arr[low] <= arr[mid]){
            ans = min (ans, arr[low]);

            low = mid + 1;
        } else {
            ans = min (ans , arr[mid]);

            high = mid - 1;
        }
    } return ans ;
}

int main(){
    vector<int> arr = {4,5,6,7,0,1,2,3};
    cout << minimum_element(arr) ;
}