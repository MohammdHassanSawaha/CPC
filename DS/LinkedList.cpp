struct linkedList
{
    map<int, int> nxt;
    map<int, int> prev;
    linkedList() {}
    void init()
    {
        int n;
        cin >> n;
        vector<int> vec;
        vec.push_back(0);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            vec.push_back(x);
        }
        vec.push_back(inf);
        for (int j = 0; j < (int)vec.size() - 1; j++)
        {
            nxt[vec[j]] = vec[j + 1];
        }
        for (int j = 1; j < (int)vec.size(); j++)
        {
            prev[vec[j]] = vec[j - 1];
        }
        // int node=nxt[0];
        // while(node!=inf){
        //     cout<<node<<" ";
        //     node=nxt[node];
        // }cout<<endl;
    }
    void insert(int x, int y)
    {
        nxt[y] = nxt[x];
        prev[y] = x;
        prev[nxt[y]] = y;
        nxt[x] = y;
    }
    void _del(int x)
    {
        prev[nxt[x]] = prev[x];
        nxt[prev[x]] = nxt[x];
    }
};