// Matrix Exponentiation
// Computes M^n in O(K^3 log N) where K is the matrix dimension.
// Commonly used for linear recurrence (e.g., Fibonacci in O(log N)).

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1e9 + 7;

typedef vector<vector<ll>> Matrix;

int K; // matrix dimension

Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C(K, vector<ll>(K, 0));
    for (int i = 0; i < K; i++)
        for (int k = 0; k < K; k++) {
            if (A[i][k] == 0) continue;
            for (int j = 0; j < K; j++)
                C[i][j] = (C[i][j] + A[i][k] % MOD * B[k][j]) % MOD;
        }
    return C;
}

Matrix mat_pow(Matrix M, ll n) {
    Matrix result(K, vector<ll>(K, 0));
    // Identity matrix
    for (int i = 0; i < K; i++) result[i][i] = 1;
    while (n > 0) {
        if (n & 1) result = multiply(result, M);
        M = multiply(M, M);
        n >>= 1;
    }
    return result;
}

// Example: Fibonacci using matrix exponentiation
// F(n) = F(n-1) + F(n-2), F(0) = 0, F(1) = 1
// [F(n+1)]   [1 1]^n   [F(1)]
// [F(n)  ] = [1 0]   * [F(0)]
ll fibonacci(ll n) {
    if (n == 0) return 0;
    K = 2;
    Matrix M = {{1, 1}, {1, 0}};
    Matrix result = mat_pow(M, n - 1);
    return result[0][0]; // F(n)
}

int main() {
    // Fibonacci numbers
    for (int i = 0; i <= 10; i++) {
        cout << "F(" << i << ") = " << fibonacci(i) << "\n";
    }

    // Matrix exponentiation for custom recurrences:
    // Define your transition matrix and initial vector,
    // then use mat_pow to compute the n-th term efficiently.
    return 0;
}
