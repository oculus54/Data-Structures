#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> traversalBFS(int V, vector<int> adj[]){
    vector<int> isVisited(V, 0); // visited array
    vector<int> bfsTraversal;

    for(int start = 0; start < V; start++) {
        if(!isVisited[start]) {
            queue<int> q;
            q.push(start);
            isVisited[start] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();
                bfsTraversal.push_back(node);

                for(auto it: adj[node]) {
                    if(!isVisited[it]) {
                        isVisited[it] = 1;
                        q.push(it);
                    }
                }
            }
        }
    }
    return bfsTraversal;
}

int main()
{
    int n, m;
    cout<<"Enter the number of Nodes: ";
    cin>>n;
    cout<<"Enter the number of Edges: ";
    cin>>m;

    vector<int> adj[n];
    for(int i = 0; i < m; i++) {
        int u, v;
        cout<<"Enter source node and target node: ";
        cin>>u>>v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u); // undirected
    }

    vector<int> bfsArray = traversalBFS(n, adj);
    cout << "BFS Traversal: ";
    for(auto i : bfsArray)
        cout << i << " ";

    return 0;
}
