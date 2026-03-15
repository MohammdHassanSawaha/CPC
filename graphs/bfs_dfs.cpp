// BFS and DFS on an undirected/directed graph
// Time: O(V + E), Space: O(V)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
bool visited[MAXN];

// Breadth-First Search
void bfs(int src, int n) {
    fill(visited, visited + n + 1, false);
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        // process u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// Depth-First Search (iterative)
void dfs_iterative(int src, int n) {
    fill(visited, visited + n + 1, false);
    stack<int> s;
    visited[src] = true;
    s.push(src);
    while (!s.empty()) {
        int u = s.top(); s.pop();
        // process u
        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                s.push(v);
            }
        }
    }
}

// Depth-First Search (recursive)
void dfs(int u) {
    visited[u] = true;
    // process u
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove for directed graph
    }

    fill(visited, visited + n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i); // or bfs(i, n)
        }
    }
    return 0;
}
