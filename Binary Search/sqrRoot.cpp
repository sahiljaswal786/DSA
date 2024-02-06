#include <bits/stdc++.h>
using namespace std;

int squareRoot(int n){
    int low = 1;
    int high = n;
    int ans;

    while(low <= high){
        int mid = (low + high)/2;

        if ((mid * mid) >= n){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }  
    } return ans;
}


int main(){
    int n;
    cin >> n ;
    cout << squareRoot(n);
}