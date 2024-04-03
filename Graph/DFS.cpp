#include <bits/stdc++.h>
using namespace std;

void dfs (vector<int> adj[], int start_node, int visited[], vector<int>& ans){
     visited[start_node] = 1;
     ans.push_back(start_node);

     for (auto it: adj[start_node]){
        if(visited[it] == 0){
            dfs(adj, it , visited, ans);
        }
     }
}

vector<int> dfsOfGraph(vector<int> adj[], int V ){
    vector<int> ans;
    int visited[V] ={0};

    dfs (adj, 0 , visited, ans);

    return ans;

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
    // adj[5] is empty as it's not connected to any other vertex

    vector<int> result = dfsOfGraph(adj, V);

    // Printing BFS traversal result
    cout << "DFS Traversal starting from node 0: ";
    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}