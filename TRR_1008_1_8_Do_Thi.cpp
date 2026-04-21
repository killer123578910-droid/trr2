#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t, n;
    in >> t;
    in >> n;
    vector<vector<int>> ke(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        in >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            in >> y;
            ke[i].push_back(y);
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            out << ke[i].size() << " ";
    }
    else
    {
        set<pair<int, int>> e;
        for (int i = 1; i <= n; i++)
        {
            for (auto x : ke[i])
            {
                if (!e.count({x, i}))
                    e.insert({i, x});
            }
        }
        out << n << " " << e.size() << endl;
        for (auto x : e)
            out << x.first << " " << x.second << endl;
    }

    return 0;
}