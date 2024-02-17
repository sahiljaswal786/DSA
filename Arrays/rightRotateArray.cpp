#include<bits/stdc++.h>
using namespace std;

void rightRotate(vector<int> &arr , int k){
    int n = arr.size();

    k =  k % n;

    int temp [k];

    for( int i = n - k; i < n ; i++){
        temp [i-n + k] = arr[i];
    }

    for( int i = n - k - 1; i >= 0 ; i--){
        arr [i + k] = arr[i];
    }

    for( int i=0 ; i < k; i++){
        arr[i] = temp[i];
    }
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    int k = 12;
    rightRotate(arr , k);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}