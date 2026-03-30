// Sorting Algorithms
// Merge Sort: O(N log N), stable
// Quick Sort: O(N log N) average, O(N^2) worst case
// Counting Sort: O(N + K) for integer keys in [0, K]

#include <bits/stdc++.h>
using namespace std;

// ---- Merge Sort ----
void merge_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    merge_sort(arr, l, mid);
    merge_sort(arr, mid + 1, r);

    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else tmp.push_back(arr[j++]);
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = tmp[k - l];
}

// Count inversions while merging
long long merge_count(vector<int>& arr, int l, int r) {
    if (l >= r) return 0;
    int mid = l + (r - l) / 2;
    long long cnt = merge_count(arr, l, mid) + merge_count(arr, mid + 1, r);

    vector<int> tmp;
    int i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) tmp.push_back(arr[i++]);
        else { cnt += mid - i + 1; tmp.push_back(arr[j++]); }
    }
    while (i <= mid) tmp.push_back(arr[i++]);
    while (j <= r) tmp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = tmp[k - l];
    return cnt;
}

// ---- Quick Sort (randomized) ----
void quick_sort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    // Randomize to avoid worst-case O(N^2)
    int pivot_idx = l + rand() % (r - l + 1);
    swap(arr[pivot_idx], arr[r]);
    int pivot = arr[r];

    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[r]);
    quick_sort(arr, l, i - 1);
    quick_sort(arr, i + 1, r);
}

// ---- Counting Sort (for keys in [0, K]) ----
void counting_sort(vector<int>& arr, int K) {
    vector<int> cnt(K + 1, 0);
    for (int x : arr) cnt[x]++;
    int idx = 0;
    for (int v = 0; v <= K; v++)
        while (cnt[v]--) arr[idx++] = v;
}

int main() {
    vector<int> a = {5, 3, 8, 1, 4, 2, 7, 6};

    auto b = a;
    merge_sort(b, 0, b.size() - 1);
    cout << "Merge sort: ";
    for (int x : b) cout << x << " ";
    cout << "\n";

    auto c = a;
    quick_sort(c, 0, c.size() - 1);
    cout << "Quick sort: ";
    for (int x : c) cout << x << " ";
    cout << "\n";

    auto d = a;
    long long inv = merge_count(d, 0, d.size() - 1);
    cout << "Inversions: " << inv << "\n";

    return 0;
}
