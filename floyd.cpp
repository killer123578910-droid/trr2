#include <bits/stdc++.h>
using namespace std;
int n;
void floyd(vector<vector<int>> &ar, vector<vector<int>> &par, vector<vector<int>> &next)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (par[i][k] != INT_MAX && par[k][j] != INT_MAX &&
                    par[i][j] > par[i][k] + par[k][j])
                {
                    par[i][j] = par[i][k] + par[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
}
void traceback(vector<vector<int>> &next, int u, int v)
{
    if (!next[u][v])
    {
        cout << "NO PATH" << endl;
    }
    else
    {
        cout << u;
        int temp = u;
        while (temp != v)
        {
            temp = next[temp][v];
            cout << "--> "<<temp;
        }
    }
}
int main(){
    cin >> n;

    vector<vector<int>> ar(n + 1, vector<int>(n + 1));
    vector<vector<int>> par(n + 1, vector<int>(n + 1, INT_MAX));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];

            if (i == j)
            {
                par[i][j] = 0;
                next[i][j] = j;
            }
            else if (ar[i][j] != 0)
            {
                par[i][j] = ar[i][j];
                next[i][j] = j;
            }
        }
    }

    floyd(ar, par, next);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "K/c " << i << " -> " << j << ": " << par[i][j] << "; ";
            traceback(next, i, j);
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}