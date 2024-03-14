#include <bits/stdc++.h>
using namespace std;

int numberOfSubsequences(vector<int> &arr, int index){
    int size = arr.size();
    vector<int> ans ;
    if( index >= size) return 1;

    ans.push_back(arr[index]);
    int left = numberOfSubsequences( arr, index + 1);
    ans.pop_back();
    int right = numberOfSubsequences(arr , index + 1);
    return left + right ;
}

int main(){
    vector<int> arr ={1 ,2 ,3 };
    cout<< numberOfSubsequences(arr, 0);
}