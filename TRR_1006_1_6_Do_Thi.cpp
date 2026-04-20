#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    in>>t>>n>>m;
    vector<vector<int>> ke(n+1);
    vector<pair<int,int>> e;
    vector<vector<int>> lienthuog(n+1,vector<int>(m+1));
    for(int i=0;i<m;i++){
        int x,y;
        in>>x>>y;
        e.push_back({x,y});
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    if(t==1){
        for(int i=1;i<=n;i++) out<<ke[i].size()<<" ";
    }else{
        out<<n<<" "<<m<<endl;
        int k=1;
        for(auto x:e){
            lienthuog[x.first][k]=1;
            lienthuog[x.second][k]=1;
            k++;
            
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                out<<lienthuog[i][j]<<" ";
            }
            out<<endl;
        }
    }
    return 0;
}