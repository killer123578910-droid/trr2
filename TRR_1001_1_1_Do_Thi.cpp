#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n;
    in>>t;
    in>>n;
    vector<int> bac(n+1);
    vector<pair<int,int>> ke;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x!=0 && i<j){
                ke.push_back({i,j});
                bac[i]+=x;
                bac[j]+=x;
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++) out<<bac[i]<<" ";

    }else{
        out<<n<<" "<<ke.size()<<endl;
        for(auto x:ke){
            out<<x.first<<" "<<x.second<<endl;
        }
    }
    
    return 0;
}