#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ifstream cin("DT.INP");
    //ofstream cout("DT.OUT");

    //bài này đéo nhập file được đâu
    int t, n;
    cin >> t;
    cin >> n;
    vector<vector<int>> ke(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            int y;
            cin >> y;
            ke[i].push_back(y);
        }
    }
    if (t == 1)
    {
        for (int i = 1; i <= n; i++)
            cout << ke[i].size() << " ";
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
        cout<<n<<" "<<e.size()<<endl;
        vector<vector<int>> lt(n+1,vector<int>(e.size()+1));
        int k=1;
        for(auto x:e){
            lt[x.first][k]=1;
            lt[x.second][k]=1;
            k++;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=e.size();j++){
                cout<<lt[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}