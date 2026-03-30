// KMP (Knuth-Morris-Pratt) String Matching Algorithm
// Time: O(N + M), Space: O(M)
// Finds all occurrences of pattern in text.

#include <bits/stdc++.h>
using namespace std;

// Build the failure function (prefix function) for pattern
vector<int> build_failure(const string& pattern) {
    int m = pattern.size();
    vector<int> fail(m, 0);
    for (int i = 1; i < m; i++) {
        int j = fail[i - 1];
        while (j > 0 && pattern[i] != pattern[j]) j = fail[j - 1];
        if (pattern[i] == pattern[j]) j++;
        fail[i] = j;
    }
    return fail;
}

// Returns all 0-indexed starting positions of pattern in text
vector<int> kmp_search(const string& text, const string& pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> fail = build_failure(pattern);
    vector<int> positions;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) j = fail[j - 1];
        if (text[i] == pattern[j]) j++;
        if (j == m) {
            positions.push_back(i - m + 1);
            j = fail[j - 1];
        }
    }
    return positions;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> positions = kmp_search(text, pattern);
    cout << "Pattern found at positions: ";
    for (int pos : positions) cout << pos << " ";
    cout << "\n";
    cout << "Total occurrences: " << positions.size() << "\n";
    return 0;
}
