
struct segtree
{
    ll size = 1;
    int merge(int a, int b)
    {
        return max(a, b);
    }
    int single(ll v)
    {
        return v;
    }
    vector<int> values;
    void init(ll n)
    {
        size = 1;
        while (size < n)
            size <<= 1;
        values.resize((size << 1));
    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {
        if (rx - lx == 0)
            return;
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
            {
                values[x] = single(a[lx]);
            }
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }
    void set(ll i, ll v, ll x, ll lx, ll rx)
    {
        if (rx - lx == 1)
        {
            values[x] = single(v);
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
        {
            set(i, v, 2 * x + 1, lx, m);
        }
        else
        {
            set(i, v, 2 * x + 2, m, rx);
        }
        values[x] = merge(values[2 * x + 1], values[2 * x + 2]);
    }
    void set(ll i, ll v)
    {
        set(i, v, 0, 0, size);
    }
    int calc(ll l, ll r, ll x, ll lx, ll rx)
    {
        if (lx >= r || l >= rx)
            return {INT_MIN};
        if (lx >= l && rx <= r)
            return values[x];
        ll m = (lx + rx) / 2;
        int s1 = calc(l, r, 2 * x + 1, lx, m);
        int s2 = calc(l, r, 2 * x + 2, m, rx);
        return merge(s1, s2);
    }
    int calc(ll l, ll r)
    {
        return calc(l, r, 0, 0, size);
    }
};
