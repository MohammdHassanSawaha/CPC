# CPC – Competitive Programming Algorithms

A collection of standard algorithms and data structures for competitive programming, implemented in C++.

---

## Table of Contents

### Graphs
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [bfs_dfs.cpp](graphs/bfs_dfs.cpp) | Breadth-First Search & Depth-First Search | O(V + E) |
| [dijkstra.cpp](graphs/dijkstra.cpp) | Dijkstra's Single-Source Shortest Path | O((V + E) log V) |
| [bellman_ford.cpp](graphs/bellman_ford.cpp) | Bellman-Ford (handles negative weights, detects negative cycles) | O(V · E) |
| [floyd_warshall.cpp](graphs/floyd_warshall.cpp) | Floyd-Warshall All-Pairs Shortest Path | O(V³) |
| [kruskal.cpp](graphs/kruskal.cpp) | Kruskal's Minimum Spanning Tree (uses DSU) | O(E log E) |
| [prim.cpp](graphs/prim.cpp) | Prim's Minimum Spanning Tree | O((V + E) log V) |
| [topological_sort.cpp](graphs/topological_sort.cpp) | Topological Sort – Kahn's BFS & DFS variants | O(V + E) |
| [tarjan_scc.cpp](graphs/tarjan_scc.cpp) | Tarjan's Strongly Connected Components | O(V + E) |

### Data Structures
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [segment_tree.cpp](data_structures/segment_tree.cpp) | Segment Tree with lazy propagation (range update, range sum query) | O(log N) per op |
| [fenwick_tree.cpp](data_structures/fenwick_tree.cpp) | Fenwick Tree / BIT (point update, prefix sum); includes 2D BIT | O(log N) per op |
| [dsu.cpp](data_structures/dsu.cpp) | Disjoint Set Union / Union-Find (path compression + union by rank) | O(α(N)) per op |
| [trie.cpp](data_structures/trie.cpp) | Trie (prefix tree) and Binary Trie (XOR queries) | O(L) per op |
| [sparse_table.cpp](data_structures/sparse_table.cpp) | Sparse Table for Range Minimum/Maximum Query | O(N log N) build, O(1) query |

### Strings
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [kmp.cpp](strings/kmp.cpp) | KMP String Matching (finds all occurrences of pattern in text) | O(N + M) |
| [z_algorithm.cpp](strings/z_algorithm.cpp) | Z-Algorithm (prefix function, pattern matching) | O(N + M) |
| [rabin_karp_hash.cpp](strings/rabin_karp_hash.cpp) | Rabin-Karp double hashing (pattern search, substring comparison) | O(N + M) |

### Math
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [math_utils.cpp](math/math_utils.cpp) | GCD, LCM, Extended Euclidean, modular inverse, fast power, Sieve of Eratosthenes, linear sieve, Euler's totient, combinatorics (nCr mod p) | Various |
| [matrix_exponentiation.cpp](math/matrix_exponentiation.cpp) | Matrix exponentiation (linear recurrences, e.g. Fibonacci in O(log N)) | O(K³ log N) |

### Dynamic Programming
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [dp_templates.cpp](dp/dp_templates.cpp) | LCS, LIS (O(N log N)), 0/1 Knapsack, Unbounded Knapsack | Various |

### Sorting
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [sorting.cpp](sorting/sorting.cpp) | Merge Sort (stable), Quick Sort (randomized), Counting Sort, inversion count | O(N log N) |

### Geometry
| File | Description | Time Complexity |
|------|-------------|-----------------|
| [geometry.cpp](geometry/geometry.cpp) | Convex Hull (Andrew's monotone chain), Point-in-Polygon (ray casting), Closest Pair of Points | O(N log N) |

---

## Usage

Each file is self-contained with a `main()` function demonstrating the algorithm.
Compile with:
```sh
g++ -O2 -std=c++17 -o solution <file>.cpp
```

---

## Contributing

Pull requests are welcome. Please keep each algorithm in its own file and include a brief comment header describing time/space complexity.
