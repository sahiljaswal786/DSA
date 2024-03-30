/*You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
 Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] which represent values 
and weights associated with N items respectively. Also given an integer W which represents knapsack capacity, 
find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to W.
 You cannot break an item, either pick the complete item or dont pick it (0-1 property)*/

#include <bits/stdc++.h>
using namespace std;

int Knapsack (int index , int wgt, vector<int>& value, vector<int>& weight, vector<vector<int>>& dp){
    if (index == 0 || wgt == 0) return 0;

    if(dp[index][wgt] != -1) return dp[index][wgt];

    int noTaken = Knapsack( index-1 , wgt, value, weight, dp);

    int Taken = 0;
    if (weight[index] <= wgt){
        Taken = value[index] + Knapsack( index-1 , wgt - weight[index], value, weight, dp);
    }

    return dp[index][wgt] = max (noTaken, Taken);
}

int main(){
    vector<int> value = {1,2,3};
    vector<int> weight = {4,5,1};
    int wgt = 4;

    int n = value.size();

    vector<vector<int>> dp (n , vector<int>(wgt + 1 , -1));

    cout << Knapsack( n-1 , wgt, value, weight, dp);
}