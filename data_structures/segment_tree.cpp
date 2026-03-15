// Segment Tree with lazy propagation
// Supports range sum query and range update (add value to range)
// Time: O(log N) per query/update, Space: O(N)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 4e5 + 5;

ll tree[MAXN], lazy[MAXN];

void build(int node, int start, int end, const vector<ll>& arr) {
    lazy[node] = 0;
    if (start == end) {
        tree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    build(2 * node, start, mid, arr);
    build(2 * node + 1, mid + 1, end, arr);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void push_down(int node, int start, int end) {
    if (lazy[node] != 0) {
        int mid = (start + end) / 2;
        tree[2 * node] += lazy[node] * (mid - start + 1);
        tree[2 * node + 1] += lazy[node] * (end - mid);
        lazy[2 * node] += lazy[node];
        lazy[2 * node + 1] += lazy[node];
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int l, int r, ll val) {
    if (r < start || end < l) return;
    if (l <= start && end <= r) {
        tree[node] += val * (end - start + 1);
        lazy[node] += val;
        return;
    }
    push_down(node, start, end);
    int mid = (start + end) / 2;
    update(2 * node, start, mid, l, r, val);
    update(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int l, int r) {
    if (r < start || end < l) return 0;
    if (l <= start && end <= r) return tree[node];
    push_down(node, start, end);
    int mid = (start + end) / 2;
    return query(2 * node, start, mid, l, r) +
           query(2 * node + 1, mid + 1, end, l, r);
}

int main() {
    int n;
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n, arr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Range update: add val to [l, r]
            int l, r; ll val;
            cin >> l >> r >> val;
            update(1, 1, n, l, r, val);
        } else {
            // Range sum query: sum of [l, r]
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
