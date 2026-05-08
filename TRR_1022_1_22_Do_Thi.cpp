#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n,m;
    in>>t>>n>>m;
    vector<vector<int>> ar(n+1,vector<int>(n+1,10000));
    vector<pair<int,int>> bac(n+1);
    for(int i=1;i<=m;i++){
        int x,y,z;
        in>>x>>y>>z;
        bac[y].first++;
        bac[x].second++;
        ar[x][y]=z;
    }

    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        out<<n<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i!=j){
                    out<<ar[i][j]<<" ";
                }else{
                    out<<0<<" ";
                }

            }
            out<<endl;
        }
    }
    return 0;
}