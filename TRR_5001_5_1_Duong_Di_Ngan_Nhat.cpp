#include <bits/stdc++.h>
using namespace std;
int v, n, u;
ifstream in("DN.INP");
ofstream out("DN.OUT");




int main(){
    in>>n>>u>>v;
    vector<vector<pair<int,int>>> ar(n+1);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x!=0 && x<=50){
                ar[i].push_back({j,x});
            }
        }
    }
    vector<int> pre(n+1);
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>>q;
    q.push({0,u});
    vector<int> d(n+1,INT_MAX);
    d[u]=0;
    while(!q.empty()){
        auto te=q.top();q.pop();
        if(te.first>d[te.second]){
            continue;
        }
        for(auto i:ar[te.second]){
            if(d[i.first]>d[te.second]+i.second){
                d[i.first]=d[te.second]+i.second;
                pre[i.first]=te.second;
                q.push({d[i.first],i.first});
            }
        }
    }
    if(d[v]==INT_MAX){
        out<<0;
    }else{
        out<<d[v]<<endl;
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