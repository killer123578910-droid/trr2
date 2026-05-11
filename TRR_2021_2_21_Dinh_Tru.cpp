#include <bits/stdc++.h>
using namespace std;
int n;
void dfs(int i, vector<vector<int>> &ar, vector<int> &vs)
{
    vs[i] = 1;
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
    vector<vector<int>> ar(n + 1, vector<int>(n + 1));
    vector<int> vs(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            in >> ar[i][j];
        }
    }
    int tieuchuan = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vs[i])
        {
            dfs(i, ar, vs);
            tieuchuan++;
        }
    }
    vector<int> kq;
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        fill(vs.begin(), vs.end(), 0);
        vs[i] = 1;
        for (int j = 1; j <= n; j++)
        {
            if (!vs[j])
            {
                dfs(j, ar, vs);
                cnt++;
                if(cnt>tieuchuan){
                    kq.push_back(i);
                    break;
                }
            }
        }
    }
    sort(kq.begin(),kq.end());
    out<<kq.size()<<endl;
    for(auto x:kq) out<<x<<" ";

    return 0;
}