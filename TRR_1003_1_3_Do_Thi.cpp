#include <bits/stdc++.h>
using namespace std;

int main()
{
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t, n;
    int m = 0;
    in >> t >> n;
    vector<vector<int>> ar(n+1,vector<int>(n+1,0));
    vector<vector<int>> bac(n + 1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in>>ar[i][j];
            if (ar[i][j] != 0 && i < j)
            {
                m += 1;
                bac[i].push_back(j);
                bac[j].push_back(i);
            }
        }
    }
    vector<vector<int>> matranlt(n + 1, vector<int>(m + 1, 0));
    int k = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (ar[i][j] != 0)
            {
                matranlt[i][k] = 1;
                matranlt[j][k] = 1;
                k++;
            }
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
        {
            out << bac[i].size() << ' ';
        }
    }
    else
    {
        out << n << " " << m << endl;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                out << matranlt[i][j] << " ";
            }
            out << endl;
        }
    }

    return 0;
}