// Floyd-Warshall All-Pairs Shortest Path Algorithm
// Time: O(V^3), Space: O(V^2)
// Handles negative edge weights; detects negative cycles.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;
const int MAXN = 505;

int n, m;
ll dist[MAXN][MAXN];

void floyd_warshall() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

bool has_negative_cycle() {
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;

    // Initialize distances
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v; ll w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w); // remove for directed graph
    }

    floyd_warshall();

    if (has_negative_cycle()) {
        cout << "Negative cycle detected!\n";
    } else {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] == INF) cout << "INF ";
                else cout << dist[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
