#include <bits/stdc++.h>
using namespace std;


int main (){
    // n nodes and m edges
    int n , m;  
    cin >> n;
    vector<int> adj[n+1];
    
    for (int i=1 ; i <=n; i++){
        int u, v;

        cin >> u >> v ;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;

}