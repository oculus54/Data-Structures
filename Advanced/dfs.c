#include <stdio.h>
#include <stdlib.h>

void dfs(int vertex, int adj[][10], int visited[], int n) {
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (int i = 0; i < n; i++) {
        if (adj[vertex][i] && !visited[i]) {
            dfs(i, adj, visited, n);
        }
    }
}
int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);
    int adj[10][10] = {0};
    printf("Enter edges (source destination):\n");
    for (int i = 0; i < e; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1; // For undirected graph
    }
    int visited[10] = {0};
    printf("DFS Traversal: ");
    dfs(0, adj, visited, n);
    return 0;
}