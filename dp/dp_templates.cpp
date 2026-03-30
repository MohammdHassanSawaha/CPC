// Dynamic Programming Templates
// Includes: Longest Common Subsequence (LCS),
//           Longest Increasing Subsequence (LIS),
//           0/1 Knapsack, Unbounded Knapsack

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// ---- Longest Common Subsequence (LCS) ----
// Time: O(N * M), Space: O(N * M)
int lcs(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    return dp[n][m];
}

// Reconstruct the actual LCS string
string lcs_string(const string& a, const string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    string result;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) { result += a[i - 1]; i--; j--; }
        else if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    reverse(result.begin(), result.end());
    return result;
}

// ---- Longest Increasing Subsequence (LIS) ----
// Time: O(N log N), Space: O(N)
int lis(const vector<int>& arr) {
    vector<int> tails;
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

// LIS (strictly increasing). For non-decreasing, replace lower_bound with upper_bound.

// ---- 0/1 Knapsack ----
// Time: O(N * W), Space: O(W)
// Each item can be taken at most once.
ll knapsack_01(int W, const vector<int>& weights, const vector<ll>& values) {
    int n = weights.size();
    vector<ll> dp(W + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int w = W; w >= weights[i]; w--) {
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

// ---- Unbounded Knapsack ----
// Time: O(N * W), Space: O(W)
// Each item can be taken any number of times.
ll knapsack_unbounded(int W, const vector<int>& weights, const vector<ll>& values) {
    int n = weights.size();
    vector<ll> dp(W + 1, 0);
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < n; i++) {
            if (weights[i] <= w) {
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
            }
        }
    }
    return dp[W];
}

int main() {
    // LCS
    string a = "ABCBDAB", b = "BDCABA";
    cout << "LCS length: " << lcs(a, b) << "\n";
    cout << "LCS string: " << lcs_string(a, b) << "\n";

    // LIS
    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS length: " << lis(arr) << "\n";

    // 0/1 Knapsack
    int W = 50;
    vector<int> weights = {10, 20, 30};
    vector<ll> values = {60, 100, 120};
    cout << "0/1 Knapsack max value: " << knapsack_01(W, weights, values) << "\n";

    // Unbounded Knapsack
    cout << "Unbounded Knapsack max value: " << knapsack_unbounded(W, weights, values) << "\n";
    return 0;
}
