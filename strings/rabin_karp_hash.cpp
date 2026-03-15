// Rabin-Karp Polynomial String Hashing
// Supports string matching and substring comparison in O(1)
// Time: O(N) build, O(1) per hash query, O(N+M) for pattern search

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// Double hashing to avoid collisions
const ll MOD1 = 1e9 + 7, BASE1 = 131;
const ll MOD2 = 1e9 + 9, BASE2 = 137;

struct StringHash {
    int n;
    vector<ll> h1, h2, pw1, pw2;

    StringHash(const string& s) : n(s.size()),
        h1(n + 1, 0), h2(n + 1, 0),
        pw1(n + 1, 1), pw2(n + 1, 1) {
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * BASE1 + s[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + s[i]) % MOD2;
            pw1[i + 1] = pw1[i] * BASE1 % MOD1;
            pw2[i + 1] = pw2[i] * BASE2 % MOD2;
        }
    }

    // Get hash of s[l..r] (0-indexed, inclusive)
    pair<ll, ll> get(int l, int r) {
        ll v1 = (h1[r + 1] - h1[l] * pw1[r - l + 1] % MOD1 + MOD1 * 2) % MOD1;
        ll v2 = (h2[r + 1] - h2[l] * pw2[r - l + 1] % MOD2 + MOD2 * 2) % MOD2;
        return {v1, v2};
    }

    // Compare s[l1..r1] with s[l2..r2]
    bool equal(int l1, int r1, int l2, int r2) {
        return get(l1, r1) == get(l2, r2);
    }
};

// Find all occurrences of pattern in text (Rabin-Karp)
vector<int> rabin_karp(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    if (m > n) return {};

    StringHash th(text), ph(pattern);
    auto pat_hash = ph.get(0, m - 1);

    vector<int> positions;
    for (int i = 0; i + m - 1 < n; i++) {
        if (th.get(i, i + m - 1) == pat_hash) {
            positions.push_back(i);
        }
    }
    return positions;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = rabin_karp(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : positions) cout << pos << " ";
    cout << "\n";
    cout << "Total occurrences: " << positions.size() << "\n";

    // Example: compare substrings using hashing
    StringHash sh(text);
    // Are text[0..2] and text[3..5] equal?
    if (text.size() >= 6) {
        cout << "text[0..2] == text[3..5]: "
             << (sh.equal(0, 2, 3, 5) ? "YES" : "NO") << "\n";
    }
    return 0;
}
