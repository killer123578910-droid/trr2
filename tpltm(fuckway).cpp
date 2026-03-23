#include <bits/stdc++.h>
using namespace std;
int n, cnt = 0;
void reset(vector<int> &vs){
    fill(vs.begin(),vs.end(),0);
}
int dfs(int i, vector<vector<int>> &ar, vector<int> &vs)
{
    vs[i] = 1;
    cnt += 1;
    for (int j = 1; j <= n; j++)
    {
        if (ar[i][j] && !vs[j])
        {
            dfs(j, ar, vs);
        }
    }
    return cnt;
}
void ltm(vector<vector<int>> &ar, vector<int> &vs)
{
    for (int j = 1; j <= n; j++)
    {
            cnt=0;
            reset(vs);
            int temp = dfs(j, ar, vs);
            if (temp < n)
            {
                cout << "NOT STRONGLY CONNECTED";
                return;
            }
    }
    cout << "STRONGLY CONNECTED";
    return;
}
int main()
{
    cin >> n;
    vector<vector<int>> ar(n + 1, vector<int>(n + 1, 0));
    vector<int> vs(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }
    ltm(ar,vs);

    return 0;
}