#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n;
    in>>t>>n;
    vector<tuple<int,int,int>> edge;
    vector<pair<int,int>> bac(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x!=10000 && x!=0){
                bac[j].first++;
                bac[i].second++;
                edge.push_back({i,j,x});
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        out<<n<<" "<<edge.size()<<endl;
        for(auto x:edge){
            out<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<endl;
        }
    }
    return 0;
}