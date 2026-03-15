// Prim's Minimum Spanning Tree Algorithm
// Time: O((V + E) log V), Space: O(V + E)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

const ll INF = 1e18;
const int MAXN = 1e5 + 5;

vector<pair<int, ll>> adj[MAXN]; // {neighbor, weight}

// Returns MST weight, or -1 if graph is disconnected.
ll prim(int src, int n) {
    vector<ll> key(n + 1, INF);
    vector<bool> in_mst(n + 1, false);
    priority_queue<pli, vector<pli>, greater<pli>> pq;

    key[src] = 0;
    pq.push({0, src});
    ll mst_weight = 0;
    int cnt = 0;

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (in_mst[u]) continue;
        in_mst[u] = true;
        mst_weight += d;
        cnt++;

        for (auto [v, w] : adj[u]) {
            if (!in_mst[v] && w < key[v]) {
                key[v] = w;
                pq.push({key[v], v});
            }
        }
    }
    return (cnt == n) ? mst_weight : -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll result = prim(1, n);
    if (result == -1) cout << "Graph is disconnected!\n";
    else cout << "MST weight: " << result << "\n";
    return 0;
}
