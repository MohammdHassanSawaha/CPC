vector<ll> kmp(const string &s)
{
    vector<ll> pi;
    pi.push_back(0);
    for (ll i = 1; i < s.size(); i++)
    {
        ll j = pi[i - 1];
        while (j && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi.push_back(j);
    }
    return pi;
}