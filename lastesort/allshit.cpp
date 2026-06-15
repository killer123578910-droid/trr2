#include<bits/stdc++.h>
using namespace std;
int n,m;

//euler
int check(int i, vector<vector<int>>&ar){
    for(int j=1;j<=n;j++){
        if(ar[i][j]){
            return j;
        }
    }
    return 0;
}

void euler(vector<vector<int>>&ar){
    vector<int> ce;
    stack<int> st;
    st.push(m);
    while(!st.empty()){
        int i=st.top();
        int k=check(i,ar);
        if(k){
            st.push(k);
            ar[i][k]=0;
            ar[k][i]=0;
        }else{
            st.pop();
            ce.push_back(i);
        }
    }
    for(int i=ce.size()-1;i>=0;i--) cout<<ce[i]<<" ";
}
//hail
void hail(int k,vector<vector<int>>&ar,vector<int>&vs, vector<int>&x){
    for(int i=1;i<=n;i++){
        if(ar[x[k-1]][i]){
            if(k==n+1&& i==m){
                for(int i=1;i<=n;i++) cout<<x[i]<<" ";
                cout<<m<<endl;
            }
        }else if(!vs[i]){
            x[k]=i;
            vs[i]=1;
            hail(k+1,ar,vs,x);
            vs[i]=0;
        }
    }
}
//kruskal
typedef struct edge{
    int x,y,z;
    edge(int x1,int y1,int z1){
        this->x=x1;
        this->y=y1;
        this->z=z1;
    }
}edge;
void init(vector<int>&p,vector<int>&sz){
    for(int i=1;i<=n;i++){
        p[i]=i;
        sz[i]=1;
    }
}
int find(int x, vector<int>&p){
    if(x==p[x]) return x;
    else return p[x]=find(p[x],p);
}
int uunion(int a,int b, vector<int>&p,vector<int>&sz){
    int a1=find(a,p);
    int b1=find(b,p);
    if(a1==b1) return  false;
    else{
        if(a1<b1) swap(a1,b1);
        sz[a1]+=sz[b1];
        p[b1]=a1;
        return true;
    }
}
//prim
void prim(vector<vector<int>>&ar,vector<int>&vs){
    vector<edge> ed;
    int dh=0;
    while(ed.size()<n-1){
        int minx,miny,minz=1e9;
        for(int i=1;i<=n;i++){
            if(vs[i]){
                for(int j=1;j<=n;j++){
                    if(ar[i][j]&&!vs[j]){
                        if(minz>ar[i][j]){
                            minz=ar[i][j];
                            minx=i;
                            minz=j;
                        }
                    }
                }
            }
        }
        if(minz==1e9) break;
        vs[miny]=1;
        dh+=minz;
        ed.push_back(edge(minx,miny,minz));
    }
    if(ed.size()<n-1) cout<<"deocoduongdau";
    else{
        for(auto x:ed) cout<<min(x.x,x.y)<<" "<<max(x.x,x.y)<<" "<<x.z;
    }
}
int main(){
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    //hail
    vector<int> vs(n+1,0),x(n+1);
    x[1]=m;
    vs[m]=1;
    hail(2,ar,vs,x);
    //kruskal
    vector<int>p,sz;
    vector<edge> ed;
    stable_sort(ed.begin(),ed.end());
    int sc=0;
    int i=0;
    int dh=0;
    while(i<ed.size()&&sc<n-1){
        if(uunion(ed[i].x,ed[i].x,p,sz)){
            sc+=1;
            dh+=ed[i].x;
        }
    }
    //prim

    
    return 0;
}