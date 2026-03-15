/*
 * @author: _Balerion
 * I think we're like fire and water I think we're like the wind and sea
 * trying to find myslef
 * who will dry your eyes when it falls apart.
 * created: 2025-12-16 20:22:33
 */
#include <bits/stdc++.h>
using namespace std;


void go()
{
    int n, m;
    cin >> n >> m;
    int q;
    vector<vector<pair<int, int>>> vec(n + 10);
    vector<vector<int>> up(n + 1, vector<int>(25));
    vector<vector<int>> mn(n + 1, vector<int>(25, 2e9));
    vector<int> dep(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        vec[u].push_back({v, c});
        vec[v].push_back({u, c});
    }
    auto dfs = [&](auto &&self, int u, int par) -> void
    {
        for (auto [v, c] : vec[u])
        {
            if (v == par)
                continue;
            dep[v] = dep[u] + 1;
            up[v][0] = u;
            mn[v][0] = c;
            for (int j = 1; j < 20; j++)
            {
                up[v][j] = up[up[v][j - 1]][j - 1];
                mn[v][j] = min(mn[up[v][j - 1]][j - 1], mn[v][j - 1]);
            }
            self(self, v, u);
        }
    };
    dfs(dfs, 1, -1);
    auto LCA = [&](int a, int b) -> int
    {
        int aa = a, bb = b;
        if (dep[a] < dep[b])
            swap(a, b);
        int k = dep[a] - dep[b];
        int node = 0;
        for (int j = 19; j >= 0; j--)
        {
            if (k & (1 << j))
            {
                a = up[a][j];
            }
        }
        if (a == b)
        {
            return a;
        }
        for (int i = 19; i >= 0; i--)
        {
            if (up[a][i] != up[b][i])
            {
                a = up[a][i];
                b = up[b][i];
            }
        }
        return up[a][0];
    };
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int lc = LCA(a, b);
        int mn1 = INT_MAX, mn2 = INT_MAX, k = abs(dep[a] - dep[lc]);
        if (k)
        {
            k--;
            for (int i = 19; i >= 0; i--)
            {
                if (k & (1 << i))
                {
                    mn1 = min(mn1, mn[a][i]), a = up[a][i];
                }
            }
            mn1 = min(mn1, mn[a][0]);
        }
        k = abs(dep[b] - dep[lc]);

        if (k)
        {
            k--;
            for (int i = 19; i >= 0; i--)
            {
                if (k & (1 << i))
                {
                    mn2 = min(mn2, mn[b][i]), b = up[b][i];
                }
            }
            mn2 = min(mn2, mn[b][0]);
        }
        cout << min(mn1, mn2) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _tt = 1;
    // cin >> _tt;
    while (_tt--)
    {
        go();
    }
}