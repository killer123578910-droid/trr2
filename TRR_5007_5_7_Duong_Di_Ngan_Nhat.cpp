#include<bits/stdc++.h>
using namespace std;
int n,u,v;
ifstream in("BN.INP");
ofstream out("BN.OUT");

int ballmanfuck(vector<vector<pair<int,int>>>&ar,vector<int>&dh,vector<int>&pre){
    for(int i=0;i<n-1;i++){
        for(int j=1;j<=n;j++){
                for(auto k:ar[j]){
                    if(dh[j]!=INT_MAX&& dh[k.first]>dh[j]+k.second){
                        dh[k.first]=dh[j]+k.second;
                        pre[k.first]=j;
                    }
                }
        }
    }
    if(dh[v]==INT_MAX) return 0;
    for(int j=1;j<=n;j++){
                for(auto k:ar[j]){
                    if(dh[k.first]>dh[j]+k.second){
                        return -1; 
                    }
                }
            }
    return dh[v];
}
int main(){
    in>>n>>u>>v;
    vector<vector<pair<int,int>>> ar(n+1);
    vector<int> dh(n+1,INT_MAX);
    vector<int> pre(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x!=0 && abs(x)<=50){
                ar[i].push_back({j,x});
            }
        }
    }
    dh[u]=0;
    int dhe=ballmanfuck(ar,dh,pre);
    if(dhe==-1) out<<dhe;
    else if(dhe==0) out<<dhe;
    else{
        out<<dhe<<endl;
         int k=v;
    stack<int> st;
    while(k!=u){
        st.push(k);
        k=pre[k];
    }
    st.push(u);
    while(!st.empty()){
        out<<st.top()<<" ";
        st.pop();
    } 
    }
    return 0;
}