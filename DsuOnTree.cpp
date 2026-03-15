/*
 * @author: y0uKn0wWh0
 * I think we're like fire and water I think we're like the wind and sea
 * trying to find myslef
 * who will dry your eyes when it falls apart.
 * created: 2026-02-01 14:00:02
 */
#include <bits/stdc++.h>
using namespace std;

void go()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), ans(n + 1);
    vector<vector<int>> vec(n + 1);
    set<int> st[n + 1];
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        st[i].insert(x);
        ans[i] = i;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    auto merge = [&](int a, int b) -> int
    {
        if (st[b].size() < st[a].size())
            swap(a, b);
        for (auto i : st[a])
            st[b].insert(i);
        st[a].clear();
        return b;
    };

    function<int(int, int)> dfs = [&](int u, int p) -> int
    {
        int cur = ans[u];
        for (auto v : vec[u])
        {
            if (v != p)
            {
                cur = merge(dfs(v, u), cur);
            }
        }
        ans[u] = st[cur].size();
        return cur;
    };

    dfs(1, 0);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
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