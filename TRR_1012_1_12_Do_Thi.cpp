#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n;
    in>>t>>n;
    vector<pair<int,int>> bac(n+1);
    vector<pair<int,int>> mt;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x; 
            in>>x;
            if(x!=0){
                mt.push_back({i,j});
                bac[i].second+=1;
                bac[j].first+=1;
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        out<<n<<" "<<mt.size()<<endl;
        for(auto x:mt){
            out<<x.first<<" "<<x.second<<endl;
        }
    }

    return 0;
}