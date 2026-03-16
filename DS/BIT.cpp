/*
 * @author: y0uKn0wWh0
 * I think we're like fire and water I think we're like the wind and sea
 * trying to find myslef
 * who will dry your eyes when it falls apart.
 * created: 2026-03-15 17:40:23
 */
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
long long bit[2 * N];g
int n;

void update(int idx, long long v)
{
    for (; idx <= 2 * n; idx += idx & -idx)
        bit[idx] += v;
}

long long query(int idx)
{
    long long s = 0;
    for (; idx > 0; idx -= idx & -idx)
        s += bit[idx];
    return s;
}
void go()
{
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _tt = 1;
    // cin >> _tt;
    while (_tt--)
    {
        go();
    }
}