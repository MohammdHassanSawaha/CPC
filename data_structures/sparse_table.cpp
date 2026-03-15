// Sparse Table for Range Minimum/Maximum Query (RMQ)
// Time: O(N log N) build, O(1) per query, Space: O(N log N)
// Note: Only works for idempotent functions (min, max, gcd, etc.)

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;
const int LOG = 17;

int n;
ll sparse[MAXN][LOG];
int log2_table[MAXN];

void build(const vector<ll>& arr) {
    for (int i = 1; i <= n; i++) sparse[i][0] = arr[i];
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            sparse[i][j] = min(sparse[i][j - 1],
                               sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
    log2_table[1] = 0;
    for (int i = 2; i <= n; i++) {
        log2_table[i] = log2_table[i / 2] + 1;
    }
}

// Range minimum query on [l, r] (1-indexed)
ll query_min(int l, int r) {
    int k = log2_table[r - l + 1];
    return min(sparse[l][k], sparse[r - (1 << k) + 1][k]);
}

// For range sum (non-idempotent), use a different approach or segment tree.

int main() {
    cin >> n;
    vector<ll> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(arr);

    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query_min(l, r) << "\n";
    }
    return 0;
}
