
#define ll long long

struct segtree
{
    int sz;
    vector<ll> sums;
    vector<ll> lazy;
    void init(int n)
    {
        sz = 1;
        while (sz < n)
            sz *= 2;
        sums.assign(2 * sz, LLONG_MAX);
        lazy.assign(2 * sz, 0);
    }
    void propagate(int v, int l, int r)
    {
        if (r - l == 1 || !lazy[v])
        {
            return;
        }
        sums[2 * v + 1] += lazy[v];
        sums[2 * v + 2] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        lazy[2 * v + 2] += lazy[v];
        lazy[v] = 0;
    }
    void put(int lx, int rx, int x, int v, int l, int r)
    {
        propagate(v, l, r);
        if (l >= rx || r <= lx)
        {
            return;
        }
        if (l >= lx && r <= rx)
        {
            sums[v] += x;
            lazy[v] = x;
            return;
        }
        int m = (l + r) / 2;
        put(lx, rx, x, 2 * v + 1, l, m);
        put(lx, rx, x, 2 * v + 2, m, r);
        sums[v] = min(sums[2 * v + 1], sums[2 * v + 2]);
    }

    void put(int lx, int rx, int x)
    {
        put(lx, rx, x, 0, 0, sz);
    }

    void build(int i, int x, int v, int l, int r)
    {
        if (r - l == 1)
        {
            sums[v] = x;
            return;
        }
        int m = (l + r) / 2;
        if (i < m)
            build(i, x, 2 * v + 1, l, m);
        else
            build(i, x, 2 * v + 2, m, r);
        sums[v] = min(sums[2 * v + 1], sums[2 * v + 2]);
    }

    void build(int i, int x)
    {
        build(i, x, 0, 0, sz);
    }

    ll get_Sum(int lx, int rx, int v, int l, int r)
    {
        propagate(v, l, r);
        if (rx <= l || lx >= r)
            return 1e12;
        if (lx <= l && rx >= r)
            return sums[v];
        int m = (l + r) / 2;
        return min(get_Sum(lx, rx, 2 * v + 1, l, m), get_Sum(lx, rx, 2 * v + 2, m, r));
    }

    ll get_Sum(int lx, int rx)
    {
        return get_Sum(lx, rx, 0, 0, sz);
    }
};
