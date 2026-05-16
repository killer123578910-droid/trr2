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
ifstream in("CK.INP");
ofstream out("CK.OUT");
int n, u;
int main(){
    in>>n>>u;
    vector<vector<pair<int,int>>> ar(n+1);
    vector<edge> mst;
    vector<int> vs(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            in>>x;
            if(x>0&&x<=50){
                ar[i].push_back({j,x});
            }
        }
    }
    int dh=0;
    vs[u]=1;
    while(mst.size()<n-1){
        int minw=INT_MAX;
        int minx,miny;
        int flag=0;
        for(int i=1;i<=n;i++){
            if(vs[i]){
                for(auto x:ar[i]){
                    if(!vs[x.first]&&minw>x.second){
                        minx=i;miny=x.first;
                        minw=x.second;
                        
                    }
                }
            }

        }
        if(minw==INT_MAX) break;
        mst.push_back(edge(minx,miny,minw));
        vs[miny]=1;
        dh+=minw;
    }
    if(mst.size()<n-1) out<<0;
    else{
        out<<dh<<endl;
        for(auto x:mst) out<<min(x.u,x.v)<<" "<<max(x.u,x.v)<<" "<<x.w<<endl;
    }

    return 0;
}