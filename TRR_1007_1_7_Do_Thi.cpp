#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t;
    in >> t;

    if (t == 1)
    {
        int n;
        in >> n;
        vector<set<int>> ke(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int x;
            in >> x;
            for (int j = 0; j < x; j++)
            {
                int y;
                in>>y;
                ke[i].insert(y);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            out << ke[i].size() << " ";
        }
    }
    else
    {
        int n;
        in >> n;
        vector<set<int>> ke(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int x;
            in >> x;
            for (int j = 0; j < x; j++)
            {
                int y;
                in>>y;
                ke[i].insert(y);
            }
        }
        out << n << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (ke[i].count(j))
                {
                    out << 1 << " ";
                }
                else
                    out << 0 << " ";
            }
            out << endl;
        }
    }

    return 0;
}