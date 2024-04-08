//Only applicable in DAG

#include <bits/stdc++.h>
using namespace std;

void dfs (int node, vector<int> adj[], int V, vector<int>& vis, stack<int>& st){
    vis[node] = 1;

    for( auto it : adj[node]){
        if(!vis[it]){
            dfs(it, adj, V, vis , st);
        }
    }

    st.push(node);
    
}

vector <int> topologicalSort( vector<int> adj[], int V){
    stack<int> st;

    vector<int> ans;
    vector<int> vis(V,0);

    for ( int i = 0; i < V; i++){
        if(!vis[i]){
            dfs(i , adj, V, vis , st);
        }
    }

    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}


int main(){
    int V = 6;

    vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};

    vector<int> res = topologicalSort(adj , V);

    for ( int i = 0; i < res.size(); i++){
        cout << res[i] << " ";
    }
}