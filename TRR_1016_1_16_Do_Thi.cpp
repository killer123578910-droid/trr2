#include<bits/stdc++.h>
using namespace std;

int main(){

    int t,n,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    in>>t>>n>>m;
    vector<vector<int>> ar(n+1);
    vector<pair<int,int>> bac(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        in>>x>>y;
        ar[x].push_back(y);
        bac[y].first++;
        bac[x].second++;
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        out<<n<<endl;
        for(int i=1;i<=n;i++){
            out<<ar[i].size()<<" ";
            for(auto x:ar[i]){
                out<<x<<" ";
            }
            out<<endl;
        }
    }
    return 0;
}