#include <bits/stdc++.h>
using namespace std;


bool detectCycle(vector<int> adj[] , int v ,int start_node){

    vector<int> vis(v, 0);

    queue<pair<int,int>>q;
    q.push({start_node,-1});
    vis[start_node] = 1;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for ( auto it : adj[node]){
            if(!vis[it]){
                q.push({it,node});
            } else if ( parent != node){
                return true;
            }
        }

    } return false;

}

int main()
{
    int V = 6; // Number of vertices
    vector<int> adj[V];

    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {3, 4};
    adj[4] = {4};

    cout << detectCycle(adj, V , 0);
}