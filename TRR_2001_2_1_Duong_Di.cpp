#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(int u,vector<vector<int>> &ar,vector<int>&vs,vector<int>&pr){
    vs[u]=1;
    for(int i=1;i<=n;i++){
        if(ar[u][i]&&!vs[i]){
            pr[i]=u;
            dfs(i,ar,vs,pr);
        }
    }
}

int main(){
    int t,u,v;
    ifstream in("TK.INP");
    ofstream out("TK.OUT");
    in>>t>>n>>u>>v;
    vector<vector<int>> ar(n+1,vector<int> (n+1,0));
    vector<int> pr(n+1),vs(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in>>ar[i][j];
        }
    }
    if(t==1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i!=u && i!=v && ar[i][v]&&ar[u][i]) cnt++;
        }
        out<<cnt<<endl;
    }
    else{
        dfs(u,ar,vs,pr);
        if(vs[v]){
            stack<int> innguoc;
            int i=v;
            while(i!=u){
                innguoc.push(i);
                i=pr[i];
            }
            innguoc.push(u);
            while(!innguoc.empty()){
                out<<innguoc.top()<<" ";
                innguoc.pop();
            }
        }
        

    }
    return 0;
}