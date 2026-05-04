#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,t,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    in>>t>>n>>m;
    vector<pair<int,int>> bac(n+1);
    vector<vector<int>> ar(n+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        int x,y;
        in>>x>>y;
        ar[x][y]=1;
        bac[y].first+=1;
        bac[x].second+=1;
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        out<<n<<endl;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                out<<ar[i][j]<<" ";
            }
            out<<endl;
        }
    }
    return 0;
}