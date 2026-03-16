const int N = 2e6;
int parent[N], sz[N];
int get(int A) { return parent[A] = (parent[A] == A ? A : get(parent[A])); }
void unite(int AA, int BB)
{
    int A = get(AA), B = get(BB);
    if (A == B)
        return;
    if (sz[A] > sz[B])
        swap(A, B);
    parent[A] = B;
    sz[B] += sz[A];
}
void init()
{
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sz[i] = 1;
    }
}
