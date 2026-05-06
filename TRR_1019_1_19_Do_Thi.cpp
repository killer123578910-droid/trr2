#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n,m;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");

    in>>t>>n;
    vector<pair<int,int>> bac(n+1);
    vector<pair<int,int>> edge;
    for(int i=1;i<=n;i++){
        int x;
        in>>x;
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
        out<<n<<" "<<edge.size()<<endl;
        for(int i=0;i<edge.size();i++){
            out<<edge[i].first<<" "<<edge[i].second<<endl;
        }
    }
}