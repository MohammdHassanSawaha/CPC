// Kruskal's Minimum Spanning Tree Algorithm
// Time: O(E log E), Space: O(V + E)
// Uses Union-Find (DSU) for cycle detection.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge& o) const { return w < o.w; }
};

struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n + 1), rank_(n + 1, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }
};

// Returns {MST weight, MST edges}. If graph is disconnected, returns a spanning forest.
pair<ll, vector<Edge>> kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll mst_weight = 0;
    vector<Edge> mst_edges;
    for (const auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            mst_weight += e.w;
            mst_edges.push_back(e);
            if ((int)mst_edges.size() == n - 1) break;
        }
    }
    return {mst_weight, mst_edges};
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    auto [weight, mst] = kruskal(n, edges);
    cout << "MST weight: " << weight << "\n";
    cout << "MST edges:\n";
    for (const auto& e : mst) {
        cout << e.u << " - " << e.v << " : " << e.w << "\n";
    }
    return 0;
}
