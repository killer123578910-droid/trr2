#include<bits/stdc++.h>
using namespace std;
int n,tieuchuan;
void reset(vector<bool> &vs){
    fill(vs.begin(),vs.end(),false);
}
void bfs(int i,vector<vector<int>> &ar,vector<bool> &vs,int n){
    vs[i]=true;
    queue<int> st;
    st.push(i);
    while(!st.empty()){
        int top=st.front();
        st.pop();
        for(int j=1;j<=n;j++){
            if(ar[top][j]&&!vs[j]){
                vs[j]=true;
                st.push(j);
            }
        }
    }
}
int sotplt(vector<vector<int>> &ar,vector<bool> &vs,int n){
    int kq=0;
        for(int i=1;i<=n;i++){
            if(!vs[i]){
                bfs(i,ar,vs,n);
                kq+=1;
        }
    }
    return kq;
}
int main(){
    cin>>n;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<bool> vs(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            bfs(i,ar,vs,n);
            tieuchuan+=1;
        }
    }
    for(int i=1;i<=n;i++){
        reset(vs);
        vs[i]=true;
        int temp=sotplt(ar,vs,n);
        if(temp>tieuchuan) cout<<i<<" ";
        
    }
}