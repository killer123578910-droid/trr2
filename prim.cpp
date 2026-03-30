#include<bits/stdc++.h>
using namespace std;
typedef struct edge{
    int x,y,w;
}edge;
int n,u;
void prim(vector<vector<pair<int,int>>>&ar,vector<bool>&used){
    vector<edge> MST;
    int dh=0;
    used[u]=true;
    while(MST.size()<n-1){
        int minw=INT_MAX;
        int z,k;
        for(int i=1;i<=n;i++){
            if(used[i]){
                for(pair<int,int> x:ar[i]){
                    if(!used[x.first]&&minw>x.second){
                        z=i;k=x.first;
                        minw=x.second;
                    }
                }
            }
        }
        MST.push_back({z,k,minw});
        used[k]=true;
        dh+=minw;
    }
    cout<<"dH = "<<dh<<endl;
    for(auto i:MST){
        cout<<min(i.x,i.y)<<" "<<max(i.y,i.x)<<endl;
    }
}
int main(){
    cin>>n>>u;
    vector<bool> used(n+1,0);
    vector<vector<pair<int,int>>> ar(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(x!=0){
                ar[i].push_back({j,x});
                ar[j].push_back({i,x});
            }
        }
    }
    prim(ar,used);
    return 0;
}