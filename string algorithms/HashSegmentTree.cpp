// palindrome queries cses

/*
 * @author: y0uKn0wWh0
 * I think we're like fire and water I think we're like the wind and sea
 * trying to find myslef
 * who will dry your eyes when it falls apart.
 * created: 2026-03-25 10:36:03
 */

#include <bits/stdc++.h>
#define F first
#define S second
#define lx node * 2
#define rx node * 2 + 1
#define md ((s + e) / 2)
#define mid ((l + r) / 2)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const int mod[] = {(ll)1e9 + 123, (ll)1e9 + 321}, p[] = {29, 31};
string t;
int pwr[2][200005];
pair<int, int> tree[2][4 * 200005];
pair<int, int> mrg(pair<int, int> a, pair<int, int> b, int len)
{
    return {((ll)a.F * pwr[0][len] + b.F) % mod[0], ((ll)a.S * pwr[1][len] + b.S) % mod[1]};
}
void build(int s, int e, int node, int i)
{
    if (s == e)
    {
        tree[i][node].F = t[s] - 'a' + 1;
        tree[i][node].S = t[s] - 'a' + 1;
        return;
    }
    build(s, md, lx, i), build(md + 1, e, rx, i);
    tree[i][node] = mrg(tree[i][lx], tree[i][rx], e - md);
}
void update(int s, int e, int node, int id, int val, int i)
{
    if (s > id || e < id)
        return;
    if (s == e)
    {
        tree[i][node] = {val, val};
        return;
    }
    update(s, md, lx, id, val, i), update(md + 1, e, rx, id, val, i);
    tree[i][node] = mrg(tree[i][lx], tree[i][rx], e - md);
}
pair<pair<int, int>, int> query(int s, int e, int node, int l, int r, int i)
{
    if (s > r || e < l)
        return {{0, 0}, 0};
    if (l <= s && e <= r)
        return {tree[i][node], e - s + 1};
    auto o1 = query(s, md, lx, l, r, i), o2 = query(md + 1, e, rx, l, r, i);
    pair<pair<int, int>, int> ret;
    ret.F = mrg(o1.F, o2.F, o2.S);
    ret.S = o1.S + o2.S;
    return ret;
}
int n, m;
void init()
{
}
void solve()
{
    cin >> n >> m;
    pwr[0][0] = pwr[1][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            pwr[j][i] = ((ll)pwr[j][i - 1] * p[j]) % mod[j];
        }
    }
    cin >> t;
    build(0, n - 1, 1, 0);
    reverse(all(t));
    build(0, n - 1, 1, 1);
    while (m--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            char c;
            int i;
            cin >> i >> c;
            update(0, n - 1, 1, i - 1, c - 'a' + 1, 0);
            update(0, n - 1, 1, n - i, c - 'a' + 1, 1);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            bool ok = query(0, n - 1, 1, l - 1, r - 1, 0).F == query(0, n - 1, 1, n - r, n - l, 1).F;
            cout << (ok ? "YES\n" : "NO\n");
        }
    }
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}