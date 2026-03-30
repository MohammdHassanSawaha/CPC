// Trie (Prefix Tree)
// Supports insert, search, and prefix count operations
// Time: O(L) per operation where L = string length, Space: O(N * L)

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int children[26];
    int count;      // number of strings ending here
    int prefix_cnt; // number of strings passing through this node
    TrieNode() : count(0), prefix_cnt(0) {
        fill(children, children + 26, -1);
    }
};

struct Trie {
    vector<TrieNode> nodes;

    Trie() { nodes.emplace_back(); }

    void insert(const string& s) {
        int cur = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) {
                nodes[cur].children[idx] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].children[idx];
            nodes[cur].prefix_cnt++;
        }
        nodes[cur].count++;
    }

    // Returns true if the exact string exists in the trie
    bool search(const string& s) {
        int cur = 0;
        for (char c : s) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) return false;
            cur = nodes[cur].children[idx];
        }
        return nodes[cur].count > 0;
    }

    // Returns true if any word in the trie starts with the given prefix
    bool starts_with(const string& prefix) {
        int cur = 0;
        for (char c : prefix) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) return false;
            cur = nodes[cur].children[idx];
        }
        return true;
    }

    // Returns the number of strings with the given prefix
    int count_prefix(const string& prefix) {
        int cur = 0;
        for (char c : prefix) {
            int idx = c - 'a';
            if (nodes[cur].children[idx] == -1) return 0;
            cur = nodes[cur].children[idx];
        }
        return nodes[cur].prefix_cnt;
    }
};

// Trie for XOR (binary trie, 30-bit integers)
struct XorTrie {
    int ch[2];
    int cnt;
    XorTrie() : cnt(0) { ch[0] = ch[1] = -1; }
};

struct BinaryTrie {
    vector<XorTrie> nodes;
    BinaryTrie() { nodes.emplace_back(); }

    void insert(int x) {
        int cur = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (x >> i) & 1;
            if (nodes[cur].ch[bit] == -1) {
                nodes[cur].ch[bit] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].ch[bit];
            nodes[cur].cnt++;
        }
    }

    // Returns max XOR of x with any number in the trie
    int max_xor(int x) {
        int cur = 0, result = 0;
        for (int i = 29; i >= 0; i--) {
            int bit = (x >> i) & 1;
            int want = 1 - bit;
            if (nodes[cur].ch[want] != -1) {
                result |= (1 << i);
                cur = nodes[cur].ch[want];
            } else if (nodes[cur].ch[bit] != -1) {
                cur = nodes[cur].ch[bit];
            } else break;
        }
        return result;
    }
};

int main() {
    Trie trie;
    int q;
    cin >> q;
    while (q--) {
        int type; string s;
        cin >> type >> s;
        if (type == 1) trie.insert(s);
        else if (type == 2) cout << (trie.search(s) ? "YES" : "NO") << "\n";
        else cout << (trie.starts_with(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}
