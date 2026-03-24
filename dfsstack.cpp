#include<bits/stdc++.h>
using namespace std;
int n;
void dfs(int i,vector<vector<int>> &ar,vector<bool> &vs,int n){
    vs[i]=true;
    stack<int> st;
    st.push(i);
    cout<<i<<" ";
    while(!st.empty()){
        int top=st.top();
        st.pop();
        for(int j=1;j<=n;j++){
            if(ar[top][j]&&!vs[j]){
                cout<<j<<" ";
                vs[j]=true;
                st.push(top);
                st.push(j);
                break;
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
    dfs(5,ar,vs,n);
}