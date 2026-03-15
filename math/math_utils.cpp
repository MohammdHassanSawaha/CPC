// Math Utilities: GCD, LCM, Extended Euclidean, Modular Arithmetic
// All functions are standard competitive programming building blocks.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Greatest Common Divisor
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }

// Least Common Multiple
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// Extended Euclidean Algorithm: ax + by = gcd(a, b)
// Returns gcd; sets x and y
ll ext_gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) { x = 1; y = 0; return a; }
    ll x1, y1;
    ll g = ext_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}

// Modular inverse of a mod m (requires gcd(a, m) = 1)
ll mod_inverse(ll a, ll m) {
    ll x, y;
    ll g = ext_gcd(a, m, x, y);
    if (g != 1) return -1; // No inverse exists
    return (x % m + m) % m;
}

// Fast power: base^exp mod m
ll power(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

// Sieve of Eratosthenes: find all primes up to n
// Time: O(N log log N), Space: O(N)
vector<int> sieve(int n) {
    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; (ll)i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
    vector<int> primes;
    for (int i = 2; i <= n; i++)
        if (is_prime[i]) primes.push_back(i);
    return primes;
}

// Linear sieve: finds all primes and smallest prime factor (SPF) up to n
// Time: O(N), Space: O(N)
vector<int> linear_sieve(int n, vector<int>& spf) {
    spf.assign(n + 1, 0);
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && (ll)i * primes[j] <= n; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
    return primes;
}

// Factorize n using smallest prime factors (requires SPF from linear sieve)
vector<pair<int,int>> factorize(int n, const vector<int>& spf) {
    vector<pair<int,int>> factors;
    while (n > 1) {
        int p = spf[n], cnt = 0;
        while (n % p == 0) { n /= p; cnt++; }
        factors.push_back({p, cnt});
    }
    return factors;
}

// Euler's totient function
ll euler_phi(ll n) {
    ll result = n;
    for (ll p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}

// Combinatorics: precompute factorials and inverse factorials mod p
const ll MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
ll fact[MAXN], inv_fact[MAXN];

void precompute_factorials(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i % MOD;
    inv_fact[n] = power(fact[n], MOD - 2, MOD);
    for (int i = n - 1; i >= 0; i--) inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] % MOD * inv_fact[k] % MOD * inv_fact[n - k] % MOD;
}

int main() {
    cout << "gcd(12, 8) = " << gcd(12, 8) << "\n";
    cout << "lcm(4, 6) = " << lcm(4, 6) << "\n";
    cout << "2^10 mod 1e9+7 = " << power(2, 10, MOD) << "\n";
    cout << "mod_inverse(3, 1e9+7) = " << mod_inverse(3, MOD) << "\n";

    auto primes = sieve(50);
    cout << "Primes up to 50: ";
    for (int p : primes) cout << p << " ";
    cout << "\n";

    precompute_factorials(MAXN - 1);
    cout << "C(10, 3) = " << C(10, 3) << "\n";
    return 0;
}
