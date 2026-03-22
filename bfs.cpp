#include<bits/stdc++.h>
using namespace std;
int n;
void bfs(int i,vector<vector<int>> ar,vector<bool> &vs,int n){
    vs[i]=true;
    queue<int> st;
    st.push(i);
    while(!st.empty()){
        int top=st.front();
        st.pop();
        cout<<top<<" ";
        for(int j=1;j<=n;j++){
            if(ar[top][j]&&!vs[j]){
                vs[j]=true;
                st.push(j);
            }
        }
    }
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
    bfs(1,ar,vs,n);
}