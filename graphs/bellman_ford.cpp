// Bellman-Ford Shortest Path Algorithm (single source)
// Time: O(V * E), Space: O(V)
// Handles negative edge weights; detects negative cycles.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

struct Edge {
    int u, v;
    ll w;
};

// Returns distances from src, or empty vector if a negative cycle is reachable.
vector<ll> bellman_ford(int src, int n, const vector<Edge>& edges) {
    vector<ll> dist(n + 1, INF);
    dist[src] = 0;

    // Relax all edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (const auto& e : edges) {
            if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }

    // Check for negative cycles
    for (const auto& e : edges) {
        if (dist[e.u] != INF && dist[e.u] + e.w < dist[e.v]) {
            return {}; // Negative cycle detected
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        // For undirected graphs, also add reverse edge
    }

    int src = 1;
    vector<ll> dist = bellman_ford(src, n, edges);
    if (dist.empty()) {
        cout << "Negative cycle detected!\n";
    } else {
        for (int i = 1; i <= n; i++) {
            cout << "dist[" << i << "] = ";
            if (dist[i] == INF) cout << "INF\n";
            else cout << dist[i] << "\n";
        }
    }
    return 0;
}
