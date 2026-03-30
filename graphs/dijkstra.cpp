// Dijkstra's Shortest Path Algorithm (single source)
// Time: O((V + E) log V), Space: O(V + E)
// Works for non-negative edge weights only.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;
const int MAXN = 1e5 + 5;

vector<pair<int, ll>> adj[MAXN]; // {neighbor, weight}

vector<ll> dijkstra(int src, int n) {
    vector<ll> dist(n + 1, INF);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w}); // remove for directed graph
    }

    int src = 1;
    vector<ll> dist = dijkstra(src, n);
    for (int i = 1; i <= n; i++) {
        cout << "dist[" << i << "] = ";
        if (dist[i] == INF) cout << "INF\n";
        else cout << dist[i] << "\n";
    }
    return 0;
}
