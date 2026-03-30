// Z-Algorithm for String Matching
// Time: O(N + M), Space: O(N + M)
// z[i] = length of the longest substring starting at s[i]
//         which is also a prefix of s.

#include <bits/stdc++.h>
using namespace std;

// Compute Z-array for string s
vector<int> z_function(const string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}

// Find all occurrences of pattern in text using Z-algorithm
// Returns 0-indexed starting positions of pattern in text
vector<int> z_search(const string& text, const string& pattern) {
    string s = pattern + "$" + text;
    vector<int> z = z_function(s);
    int m = pattern.size();
    vector<int> positions;
    for (int i = m + 1; i < (int)s.size(); i++) {
        if (z[i] == m) {
            positions.push_back(i - m - 1);
        }
    }
    return positions;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = z_search(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : positions) cout << pos << " ";
    cout << "\n";
    cout << "Total occurrences: " << positions.size() << "\n";
    return 0;
}
