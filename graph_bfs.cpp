#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100; // Maximum number of nodes

void bfs(int start, int n, int adj[MAX][MAX]) {
    bool visited[MAX] = {false}; // Track visited nodes
    queue<int> q;

    // Start BFS
    visited[start] = true;
    q.push(start);

    cout << "BFS traversal starting from node " << start << ": ";
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        // Visit all neighbors of the current node
        for (int i = 1; i <= n; ++i) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    cout << endl;
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
    cout << "Enter the starting node for BFS: ";
    cin >> start;

    bfs(start, n, adj);

    return 0;
}
