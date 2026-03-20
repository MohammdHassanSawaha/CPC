struct HASH
{
    int Pi, Mod;
    vector<int> po, ha;
    void build(string &s, int P, int M)
    {
        Pi = P, Mod = M;
        int n = s.size();
        po.resize(n + 1);
        ha.resize(n + 1);
        po[0] = 1;
        ha[0] = s[0] - 'a' + 1;
        for (int i = 1; i < n; i++)
        {
            po[i] = (long long)po[i - 1] * Pi % Mod;
            ha[i] = ((long long)ha[i - 1] * Pi + s[i] - 'a' + 1) % Mod;
        }
    }
    int get(int l, int r)
    {
        int ret = ha[r];
        if (l > 0)
            ret = ((ret - (long long)ha[l - 1] * po[r - l + 1] % Mod) + Mod) % Mod;
        return ret;
    }
} H1, H2;
