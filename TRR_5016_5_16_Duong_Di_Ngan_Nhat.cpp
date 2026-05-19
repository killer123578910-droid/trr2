#include <bits/stdc++.h>
using namespace std;
ifstream in("DN.INP");
ofstream out("DN.OUT");
int n;
int main()
{
    in >> n;
    vector<vector<pair<int, int>>> ar(n + 1);
    vector<vector<int>> dh(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> nex(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            in >> x;
            if (x != 0 && x <= 50)
            {
                ar[i].push_back({j, x});
                dh[i][j] = x;
                nex[i][j] = j;
            }
            if (x == 0)
            {
                dh[i][j] = x;
                nex[i][j] = j;
            }
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dh[i][k] != INT_MAX && dh[k][j] != INT_MAX && dh[i][j] > dh[i][k] + dh[k][j])
                {
                    dh[i][j] = dh[i][k] + dh[k][j];
                    nex[i][j] = nex[i][k];
                }
            }
        }
    }

    int best = -1;
    int u, v;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j && dh[i][j] != INT_MAX)
            {

                if (dh[i][j] > best)
                {
                    best = dh[i][j];
                    u = i;
                    v = j;
                }

                else if (dh[i][j] == best)
                {
                    if (i < u || (i == u && j < v))
                    {
                        u = i;
                        v = j;
                    }
                }
            }
        }
    }
    if (best==-1)
        out << 0 << endl;
    else
    {
        out << u << " " << v << " " << best << endl;
        int z = u;
        while (z != v)
        {
            out << z << " ";
            z = nex[z][v];
        }
        out << v;
    }

    return 0;
}