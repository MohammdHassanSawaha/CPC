// Topological Sort (Kahn's BFS algorithm)
// Time: O(V + E), Space: O(V)
// Works on Directed Acyclic Graphs (DAGs).
// Also detects if the graph has a cycle.

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int in_degree[MAXN];

// Returns topological order, or empty vector if a cycle exists.
vector<int> topological_sort(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--in_degree[v] == 0) q.push(v);
        }
    }

    if ((int)order.size() != n) return {}; // Cycle detected
    return order;
}

// DFS-based topological sort
vector<int> topo_dfs_order;
bool visited[MAXN], on_stack[MAXN];
bool cycle_found = false;

void dfs_topo(int u) {
    visited[u] = on_stack[u] = true;
    for (int v : adj[u]) {
        if (on_stack[v]) { cycle_found = true; return; }
        if (!visited[v]) dfs_topo(v);
        if (cycle_found) return;
    }
    on_stack[u] = false;
    topo_dfs_order.push_back(u);
}

vector<int> topological_sort_dfs(int n) {
    fill(visited, visited + n + 1, false);
    fill(on_stack, on_stack + n + 1, false);
    cycle_found = false;
    topo_dfs_order.clear();
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs_topo(i);
        if (cycle_found) return {};
    }
    reverse(topo_dfs_order.begin(), topo_dfs_order.end());
    return topo_dfs_order;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        in_degree[v]++;
    }

    vector<int> order = topological_sort(n);
    if (order.empty()) {
        cout << "Graph has a cycle!\n";
    } else {
        cout << "Topological order: ";
        for (int x : order) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
