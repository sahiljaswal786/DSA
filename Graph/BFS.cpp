#include <bits/stdc++.h>
using namespace std;

vector<int> bfs(vector<int> adj[], int V,  int start_node)
{
    vector<int> ans;
    queue<int> q;
    q.push(start_node);
    int visited[V] = {0};
    visited[start_node] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);     

        for( auto it : adj[node]){
            if(visited[it] == 0){
                visited[it] = 1;
                q.push(it);
            }
        }
    } return ans;
}

int main()
{

    int V = 6;          // Number of vertices
    vector<int> adj[V]; 

    adj[0] = {1, 2};
    adj[1] = {2};
    adj[2] = {0, 3};
    adj[3] = {3, 4};
    adj[4] = {4};
    // adj[5] is empty as it's not connected to any other vertex

    vector<int> result = bfs(adj , V ,0);

    // Printing BFS traversal result
    cout << "BFS Traversal starting from node 0: ";
    for (int vertex : result)
    {
        cout << vertex << " ";
    }
    cout << endl;

    return 0;
}