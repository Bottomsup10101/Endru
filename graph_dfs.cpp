#include <iostream>
using namespace std;

const int MAX = 100; // Maximum number of nodes
bool visited[MAX];    // To track visited nodes

void dfs(int node, int n, int adj[MAX][MAX]) {
    // Mark the current node as visited
    visited[node] = true;
    cout << node << " ";

    // Recur for all neighbors of the current node
    for (int i = 1; i <= n; ++i) {
        if (adj[node][i] == 1 && !visited[i]) {
            dfs(i, n, adj);
        }
    }
}

int main() {
    int n, m; // Number of nodes and edges
    int adj[MAX][MAX] = {0}; // Adjacency matrix

    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    cout << "Enter the edges (1-based indexing):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // Remove this for directed graphs
    }

    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    int start;
    cout << "Enter the starting node for DFS: ";
    cin >> start;

    // Initialize visited array
    fill(visited, visited + MAX, false);

    cout << "DFS traversal starting from node " << start << ": ";
    dfs(start, n, adj);
    cout << endl;

    return 0;
}
