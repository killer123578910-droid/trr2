#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n;
    in>>t>>n;
    vector<vector<int>> bac(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x!=0 && i<j){
                bac[i].push_back(j);
                bac[j].push_back(i);
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].size()<<' ';
        }
    }else{
        out<<n<<endl;
        for(int i=1;i<=n;i++){
            out<<bac[i].size()<<" ";
            for(auto x:bac[i]) out<<x<<" ";
            out<<endl;
        }
    }


    return 0;
}