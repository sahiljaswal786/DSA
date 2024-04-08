#include <bits/stdc++.h>
using namespace std;


vector<int> topologicalSort( vector<int> adj[], int V){
    vector<int> indegree(V, 0);

    for (int i = 0; i < V; i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < V; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for ( auto it : adj[node]){
            indegree[it]--;
            if ( indegree[it] == 0){
                q.push(it);
            }
            
        }
    } return ans;
}



int main(){
    int V = 6;

    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    vector<int> res = topologicalSort(adj , V);

    for ( int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}