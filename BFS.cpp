#include <bits/stdc++.h> // include all standard headers
using namespace std;

int main() {
    int n, m; // n is number of vertices, m is number of edges
    cin >> n >> m;

    vector<vector<int>> adj(n+1); // adjacency list to store graph

    // read edges and build adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // BFS starting from vertex 1
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(1);
    visited[1] = true;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout << u << " "; // process vertex u

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return 0;
}
