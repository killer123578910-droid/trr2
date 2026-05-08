#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    in>>t>>n;
    vector<pair<int,int>> bac(n+1);
    vector<pair<int,int>> edge;
    m=0;
    for(int i=1;i<=n;i++){
        int x;
        in>>x;
        m+=x;
        for(int j=0;j<x;j++){
            int z;
            in>>z;
            edge.push_back({i,z});
            bac[z].first++;
            bac[i].second++;
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        vector<vector<int>> lt(n+1,vector<int>(m+1,0));
        out<<n<<" "<<m<<endl;
        int k=1;
        for(auto x:edge){
            lt[x.first][k]=1;
            lt[x.second][k]=-1;
            k++;        
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                out<<lt[i][j]<<" ";
            }
            out<<endl;
        }
        
    }
}