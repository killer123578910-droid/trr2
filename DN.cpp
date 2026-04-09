#include <bits/stdc++.h>
using namespace std;

int t, n, u;
vector<pair<int, int>> kq1;

void dfs(int i, vector<vector<int>> &ar, vector<int> &vs, vector<pair<int, int>> &kq)
{
    vs[i] = true;
    for (int j = 1; j <= n; j++)
    {
        if (ar[i][j] && !vs[j])
        {
            kq.push_back({i, j}); // giữ nguyên format của bạn
            dfs(j, ar, vs, kq);
        }
    }
}

vector<pair<int, int>> bfs(int i, vector<vector<int>> &ar, vector<int> &vs)
{
    vector<pair<int, int>> kq;
    queue<int> q;
    q.push(i);
    vs[i] = true;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (ar[front][j] && !vs[j])
            {
                q.push(j);
                vs[j] = true;
                kq.push_back({front, j});
            }
        }
    }
    return kq;
}

int main()
{
    cin >> t;
    cin >> n >> u;

    vector<vector<int>> ar(n + 1, vector<int>(n + 1));
    vector<int> vs(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }

    if (t == 1)
    {
        dfs(u, ar, vs, kq1);
        
        if (kq1.size()==n-1)
        {
            cout << kq1.size() << endl;
            for (auto x : kq1)
            {
                cout << x.first << " " << x.second << endl;
            }
        }else{
            cout<<"0"<<endl;
        }
    }
    else
    {
        vector<pair<int, int>> kq = bfs(u, ar, vs);
        
        if (kq.size()==n-1)
        {
            cout << kq.size() << endl;
            for (auto x : kq)
            {
                cout << x.first << " " << x.second << endl;
            }
        }else{
            cout<<0<<endl;
        }
    }

    return 0;
}