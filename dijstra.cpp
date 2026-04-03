#include<bits/stdc++.h>
using namespace std;
int n,u;
void dijktrs(vector<vector<pair<int,int>>> &ar,vector<int>&dh,vector<int> &used,vector<int> &parent){
    dh[u]=0;
    int flag=1;
    while(flag){
        flag=0;
        int miin=INT_MAX;
        int chot=1;
        for(int i=1;i<=n;i++){
            if(!used[i]){
                if(dh[i]<miin){
                    miin=dh[i];
                    chot=i;
                }
                flag=1;
            }
        }
        for(auto x:ar[chot]){
            int dich=x.first;int tt=x.second;
            if(!used[dich]&&dh[dich]>dh[chot]+tt){
                dh[dich]=dh[chot]+tt;
                parent[dich]=chot;
            }
        }
    }

}

int main(){
    cin>>n>>u;
    vector<vector<pair<int,int>>> ar;
    vector<int> dh(n+1,INT_MAX);
    vector<int> parent(n+1),used(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
            if(x!=0){
                ar[i].push_back({j,x});
            }
        }
    }
    dijktrs(ar,dh,used,parent);

    return 0;
}