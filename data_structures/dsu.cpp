// Union-Find / Disjoint Set Union (DSU)
// Supports union by rank and path compression
// Time: O(alpha(N)) amortized per operation, Space: O(N)

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank_, size_;
    int components;

    DSU(int n) : parent(n + 1), rank_(n + 1, 0), size_(n + 1, 1), components(n) {
        iota(parent.begin(), parent.end(), 0);
    }

    // Find with path compression
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    // Union by rank; returns false if already in the same set
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        if (rank_[x] < rank_[y]) swap(x, y);
        parent[y] = x;
        size_[x] += size_[y];
        if (rank_[x] == rank_[y]) rank_[x]++;
        components--;
        return true;
    }

    bool same(int x, int y) { return find(x) == find(y); }

    int get_size(int x) { return size_[find(x)]; }
};

int main() {
    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++) {
        int type, u, v;
        cin >> type >> u >> v;
        if (type == 1) {
            dsu.unite(u, v);
        } else {
            cout << (dsu.same(u, v) ? "YES" : "NO") << "\n";
        }
    }
    return 0;
}
