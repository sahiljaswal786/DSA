#include<bits/stdc++.h>
using namespace std;

void moveZerostoEnd(vector<int> &arr){
    int low = 0;
    int high = arr.size() - 1;

    if (arr[high] == 0){
        while (arr[high] == 0){
            high --;
        }
    }

    while (low <= high){
        if (arr[low] == 0 && arr[high] != 0){
            swap(arr[low] , arr[high]);
            low ++;
            high --;
        } 
        if (arr[low] != 0 && arr[high] != 0){
            low ++;
        }
    }
}

int main(){
    vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};

    moveZerostoEnd(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }

    return 0;
}