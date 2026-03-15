// Fenwick Tree (Binary Indexed Tree - BIT)
// Supports point update and prefix sum query
// Time: O(log N) per operation, Space: O(N)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

ll bit[MAXN];
int n;

// Add val to index i (1-indexed)
void update(int i, ll val) {
    for (; i <= n; i += i & (-i))
        bit[i] += val;
}

// Prefix sum [1, i]
ll query(int i) {
    ll sum = 0;
    for (; i > 0; i -= i & (-i))
        sum += bit[i];
    return sum;
}

// Range sum [l, r]
ll query(int l, int r) {
    return query(r) - query(l - 1);
}

// Point update: set arr[i] = val (requires knowing previous value)
void set_val(int i, ll old_val, ll new_val) {
    update(i, new_val - old_val);
}

// --- 2D Fenwick Tree ---
const int MAXN2 = 505;
ll bit2d[MAXN2][MAXN2];
int n2, m2;

void update2d(int x, int y, ll val) {
    for (int i = x; i <= n2; i += i & (-i))
        for (int j = y; j <= m2; j += j & (-j))
            bit2d[i][j] += val;
}

ll query2d(int x, int y) {
    ll sum = 0;
    for (int i = x; i > 0; i -= i & (-i))
        for (int j = y; j > 0; j -= j & (-j))
            sum += bit2d[i][j];
    return sum;
}

// Sum over rectangle [x1,y1] to [x2,y2]
ll query2d(int x1, int y1, int x2, int y2) {
    return query2d(x2, y2) - query2d(x1 - 1, y2)
         - query2d(x2, y1 - 1) + query2d(x1 - 1, y1 - 1);
}

int main() {
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        update(i, arr[i]);
    }

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            // Point update: add val to position i
            int i; ll val;
            cin >> i >> val;
            update(i, val);
        } else {
            // Range sum query [l, r]
            int l, r;
            cin >> l >> r;
            cout << query(l, r) << "\n";
        }
    }
    return 0;
}
