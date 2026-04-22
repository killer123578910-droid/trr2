#include<bits/stdc++.h>
using namespace std;

int main(){
    int t,n;
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    in>>t>>n;
    vector<tuple<int,int,int>> ke;
    vector<int> bac(n+1,0); 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x!=10000 && x!=0){
                if(i<j){
                ke.push_back({i,j,x});
                }
                bac[i]+=1;
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++) out<<bac[i]<<" ";
    }else{
        out<<n<<" "<<ke.size()<<endl;
        for(auto x:ke){
            out<<get<0>(x)<<" "<<get<1>(x)<<" "<<get<2>(x)<<endl;
        }
    }
    return 0;
}