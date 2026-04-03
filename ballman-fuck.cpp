#include <bits/stdc++.h>
using namespace std;
int n, u;
void bellmass(vector<vector<int>> &ar, vector<int> &dh, vector<int> &parent)
{
    dh[u] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (j!=u)
            {
                for (int k = 1; k <= n; k++)
                {
                    if(ar[k][j]!=0&&dh[k]!=INT_MAX&&dh[j]>dh[k]+ar[k][j]){
                        dh[j]=dh[k]+ar[k][j];
                        parent[j]=k;
                    }
                }
            }
        }
    }
}

int main()
{
    cin >> n >> u;
    vector<vector<int>> ar(n + 1,vector<int>(n+1));
    vector<int> dh(n + 1, INT_MAX);
    vector<int> parent(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin>>ar[i][j];
        }
    }
    bellmass(ar, dh, parent);
    for (int i = 1; i <= n; i++)
    {
        cout << "K/c " << u << " <- " << i << " = " << (dh[i] == INT_MAX ? "INF" : to_string(dh[i])) << ";  ";
        if (dh[i] == INT_MAX)
            cout << endl;
        else
        {
            int tmp = i;
            if (i == u)
            {
                cout << i << " <- " << u << endl;
            }
            else
            {
                while (tmp != u)
                {
                    cout << tmp << " <- ";
                    tmp = parent[tmp];
                }
                cout << u << endl;
            }
        }
    }

    return 0;
}