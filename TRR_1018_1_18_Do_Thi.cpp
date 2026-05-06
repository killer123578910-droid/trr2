#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    in>>t>>n;
    vector<pair<int,int>> bac(n+1);
    vector<vector<int>> ar(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        int x;
        in>>x;
        for(int j=0;j<x;j++){
            int z;
            in>>z;
            ar[i][z]=1;
            bac[z].first++;
            bac[i].second++;
        }
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
}