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

    // DFS starting from vertex 1
    vector<bool> visited(n+1, false);
    stack<int> s;
    s.push(1);

    while (!s.empty()) {
        int u = s.top();
        s.pop();

        if (!visited[u]) {
            visited[u] = true;
            cout << u << " "; // process vertex u

            // push unvisited neighbors onto stack
            for (int i = adj[u].size()-1; i >= 0; i--) {
                int v = adj[u][i];
                if (!visited[v]) {
                    s.push(v);
                }
            }
        }
    }

    return 0;
}
