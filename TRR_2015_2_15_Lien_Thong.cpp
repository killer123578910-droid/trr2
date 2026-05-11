#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
void dfs(int i, vector<vector<int>> &ar, vector<int> &vs)
{
    vs[i] = 1;
    cnt++;
    for (int j = 1; j <= n; j++)
    {
        if (ar[i][j] && !vs[j])
        {
            vs[j] = 1;
            dfs(j, ar, vs);
        }
    }
}
int main()
{
    ifstream in("TK.INP");
    ofstream out("TK.OUT");
    in >> n;
    vector<vector<int>> ar(n + 1, vector<int>(n + 1)), clone(n + 1, vector<int>(n + 1));
    vector<int> vs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in >> ar[i][j];
            if (ar[i][j])
            {
                clone[i][j] = 1;
                clone[j][i] = 1;
            }
        }
    }
    dfs(1, clone, vs);
    if (cnt < n)
    {
        out << 0;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cnt = 0;
            fill(vs.begin(), vs.end(), 0);
            dfs(i, ar, vs);
            if (cnt < n)
            {
                out << 2;
                return 0;
            }
        }
        out << 1;
    }
    return 0;
}