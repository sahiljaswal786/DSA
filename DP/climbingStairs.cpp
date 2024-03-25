// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

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

