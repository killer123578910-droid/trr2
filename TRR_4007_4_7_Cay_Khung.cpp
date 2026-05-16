#include <bits/stdc++.h>
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
int n, u;
vector<int> parent;
vector<int> sz;

void init(){
    parent.resize(n+1);
    sz.resize(n+1);
    for(int i=1;i<=n;i++){
        parent[i]=i;
        sz[i]=1;
    }
}

ifstream in("CK.INP");
ofstream out("CK.OUT");
int find(int u){
    if(u==parent[u]) return u;
    else return parent[u]=find(parent[u]);   
}
bool unionn(int a,int b){
    int x=find(a);
    int y=find(b);
    if(x==y){
        return false;
    }else{
        if(sz[x]>sz[y]) swap(x,y);
        parent[x]=y;
        sz[y]+=sz[x];
        return true;
    }

}
bool cmp(edge a,edge b){
    return a.w<b.w;
}

int main()
{
    in >> n >> u;
    vector<edge> ed;
    
    init();
    for(int i=0;i<u;i++){
        int x,y,z;
        in>>x>>y>>z;
        ed.push_back(edge(x,y,z));
    }
    stable_sort(ed.begin(),ed.end(),cmp);
    int i=0,sc=0,dh=0;
    vector<edge> kq;
    while(i<ed.size()&&sc<n-1){
        if(unionn(ed[i].u,ed[i].v)){
            sc+=1;
            dh+=ed[i].w;
            kq.push_back(ed[i]);
        }
        i++;
    }
    if(sc!=n-1){
        out<<0;
    }else{
        out<<dh<<endl;
        for(auto x: kq){
            out<<x.u<<" "<<x.v<<" "<<x.w<<endl;
        }
    }


    return 0;
}