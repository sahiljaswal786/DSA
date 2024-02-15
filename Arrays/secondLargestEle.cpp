#include<bits/stdc++.h>
using namespace std;

int secondLargestElement(vector<int> &arr){
    int large = INT_MIN;
    int secondLarge =  INT_MIN;

    for ( int i = 0 ; i< arr.size(); i++){
        if( arr[i] > large){
            secondLarge = large;
            large = arr[i];
            
        } else if (arr[i] > secondLarge && large != arr[i]){
            secondLarge = arr[i];
        }
    } return secondLarge;
}

int main(){
    vector<int> arr = {11 , 3 , 6 , 8 , 10, 15};
    cout << secondLargestElement(arr);
}