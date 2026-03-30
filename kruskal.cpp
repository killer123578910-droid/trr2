#include<bits/stdc++.h>
using namespace std;
typedef struct edge{
    int u;
    int v;
    int w;
    edge(){}
    edge(int k,int l,int m){
        this->u=k;
        this->v=l;
        this->w=m;
    }
}edge;
int n;
vector<int> parent,sz;
void init(){
    parent.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}
int find(int u){
    if(u==parent[u]) return parent[u]=u;
    return parent[u]=find(parent[u]);;
}
bool unionn(int a,int b){
    int so1=find(a);
    int so2=find(b);
    if(so1==so2){
        return false;
    }else{
        if(sz[so2]>sz[so1]){
            swap(so1,so2);
        }
        sz[so1]+=sz[so2];
        parent[so2]=so1;
        return true;
    }
}
bool cmp(edge a,edge b){
    return a.w<b.w;
}
int main(){
    cin>>n;
    vector<vector<int>> a(n+1,vector<int>(n+1));
    vector<edge> ar;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>a[i][j];
            if(a[i][j]!=0&&i<j){
                edge temp=edge(i,j,a[i][j]);
                ar.push_back(temp);
            }
        }
    }
    init();
    stable_sort(ar.begin(),ar.end(),cmp);
    int i=0,sc=0,dh=0;
    vector<edge> ans;
    while(i<ar.size()-1&&sc<n-1){
        if(unionn(ar[i].u,ar[i].v)){
            sc+=1;
            dh+=ar[i].w;
            ans.push_back(ar[i]);
        }
        i++;
    }
    cout<<"dH = "<<dh<<endl;
    for(auto x:ans){
        cout<<x.u<<" "<<x.v<<endl;
    }
    return 0;
}