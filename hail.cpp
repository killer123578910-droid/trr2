#include<bits/stdc++.h>
using namespace std;
int n,u;
void hail(int i,vector<vector<int>>&ar,vector<int> &vs,vector<int> &x){
    for(int j=1;j<=n;j++){
        if(ar[x[i-1]][j]){
            if(i==n+1&&j==u){
                for(int t=1;t<=n;t++){
                    cout<<x[t]<<" ";
                }
                cout<<u<<endl;
            }else if(!vs[j]){
                x[i]=j;
                vs[j]=1;
                hail(i+1,ar,vs,x);
                vs[j]=0;
            }
        }
    }
}
int main(){
    cin>>n>>u;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<int> vs(n+1,0),x(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    x[1]=u;
    vs[u]=1;
    hail(2,ar,vs,x);

    return 0;
}