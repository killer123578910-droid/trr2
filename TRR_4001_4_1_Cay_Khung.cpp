#include <bits/stdc++.h>
using namespace std;
int t, n, u;
ifstream in("CK.INP");
ofstream out("CK.OUT");
vector<pair<int, int>> bfs(int i, vector<int> &vs, vector<vector<int>> &ar)
{
    vector<pair<int, int>> kq;
    queue<int> q;
    q.push(i);
    vs[i] = 1;
    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (ar[front][j] && !vs[j])
            {
                kq.push_back({front, j});
                vs[j] = 1;
                q.push(j);
            }
        }
    }
    return kq;
}
void dfs(int i, vector<vector<int>> &ar, vector<int> &vs, vector<pair<int, int>> &kq)
{
    vs[i] = 1;
    for (int j = 1; j <= n; j++)
    {
        if (ar[i][j] && !vs[j])
        {
            kq.push_back({i, j});
            dfs(j, ar, vs, kq);
        }
    }
}

int main()
{
    in >> t; 
    in >> n >> u;
    vector<vector<int>> ar(n + 1, vector<int>(n + 1));
    vector<int> vs(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in >> ar[i][j];
        }
    }
    int si = n - 1;
    if (t == 1)
    {
        vector<pair<int, int>> kq;
        dfs(u, ar, vs, kq);

        if (kq.size() == si)
        {
            out << kq.size() << endl;
            for (auto x : kq)
            {
                out << min(x.first,x.second) << " " << max(x.first,x.second) << endl;
            }
        }
        else
        {
            out << 0;
        }
    }
    else
    {
        vector<pair<int, int>> kq = bfs(u, vs, ar);
        if (kq.size() == si)
        {
            out << kq.size() << endl;
            for (auto x : kq)
            {
                out << min(x.first,x.second) << " " << max(x.first,x.second) << endl;
            }
        }
        else
        {
            out << 0;
        }
    }

    return 0;
}