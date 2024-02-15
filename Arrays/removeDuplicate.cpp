#include<bits/stdc++.h>
using namespace std;

int removeDuplicate(vector<int> &arr){
    int i = 0;
    for (int j = 1 ; j < arr.size(); j++){
        if(arr[i] != arr[j]){
            i++;
        }
    } return i+1;
}


int main(){
    vector<int>arr = {1,1,2};
    cout << removeDuplicate(arr);
}