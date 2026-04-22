#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    in>>t>>n>>m;
    vector<vector<pair<int,int>>> ke(n+1);
    for(int i=0;i<m;i++){
        int x,y,z;
        in>>x>>y>>z;
        ke[x].push_back({y,z});
        ke[y].push_back({x,z});
    }
    if(t==1){
        for(int i=1;i<=n;i++) out<<ke[i].size()<<" ";
    }else{
        out<<n<<endl;
        vector<vector<int>> ar(n+1,vector<int>(n+1,10000));
        for(int i=1;i<=n;i++){
            ar[i][i]=0;
            for(auto x:ke[i]){
                ar[i][x.first]=x.second;
                ar[x.first][i]=x.second;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                out<<ar[i][j]<<" ";
            }
            out<<endl;
        }
    }
    return 0;
}