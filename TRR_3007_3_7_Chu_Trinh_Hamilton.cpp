#include<bits/stdc++.h>
using namespace std;
ifstream in("CT.INP");
ofstream out("CT.OUT");
int n,u,cnt;
void halminton(int i,vector<vector<int>>&ar,vector<int>&vs,vector<int>&x){
    for(int j=1;j<=n;j++){
        if(ar[x[i-1]][j]){
            if(i==n+1&&j==u){
                cnt++;
                for(int k=1;k<=n;k++){
                    out<<x[k]<<" ";
                }
                out<<u<<endl;
            }else if(!vs[j]){
                x[i]=j;
                vs[j]=1;
                halminton(i+1,ar,vs,x);
                vs[j]=0;
            }
        }
    }

}
int main(){
    
    in>>n>>u;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<int> vs(n+1,0),x(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in>>ar[i][j];
        }
    }
    x[1] = u;
    vs[u] = true;
    cnt=0;
    halminton(2,ar,vs,x);
    out<<cnt;

    return 0;
}