// Tarjan's Algorithm for Strongly Connected Components (SCCs)
// Time: O(V + E), Space: O(V)

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
vector<int> adj[MAXN];
int disc[MAXN], low[MAXN], timer_val = 0;
bool on_stack[MAXN];
stack<int> stk;
int scc_id[MAXN], scc_count = 0;

void tarjan_dfs(int u) {
    disc[u] = low[u] = ++timer_val;
    stk.push(u);
    on_stack[u] = true;

    for (int v : adj[u]) {
        if (!disc[v]) {
            tarjan_dfs(v);
            low[u] = min(low[u], low[v]);
        } else if (on_stack[v]) {
            low[u] = min(low[u], disc[v]);
        }
    }

    // If u is a root of an SCC
    if (low[u] == disc[u]) {
        scc_count++;
        while (true) {
            int v = stk.top(); stk.pop();
            on_stack[v] = false;
            scc_id[v] = scc_count;
            if (v == u) break;
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
    }

    fill(disc, disc + n + 1, 0);
    fill(on_stack, on_stack + n + 1, false);

    for (int i = 1; i <= n; i++) {
        if (!disc[i]) tarjan_dfs(i);
    }

    cout << "Number of SCCs: " << scc_count << "\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " -> SCC " << scc_id[i] << "\n";
    }
    return 0;
}
