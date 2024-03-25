#include <bits/stdc++.h>
using namespace std;

int climbingStairs(int n){
    if ( n == 0 ) return 1;
    if ( n < 1 ) return 0;

    int x = climbingStairs( n -1 );
    int y = climbingStairs (n - 2);
    return x + y;
}

int main(){
    int n;
    cin >> n ;
    cout << climbingStairs(n);
}

