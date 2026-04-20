#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n,m;
    in>>t>>n>>m;
    vector<vector<int>> ke(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        in>>x>>y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<ke[i].size()<<" ";
        }
    }else{
        out<<n<<endl;
        for(int i=1;i<=n;i++){
            out<<ke[i].size()<<" ";
            for(auto x:ke[i]) out<<x<<" ";
            out<<endl;
        }

        out<<endl;
    }

    return 0;
}