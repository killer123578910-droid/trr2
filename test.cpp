#include<bits/stdc++.h>
using namespace std;
int n,st;
void dfs(int i,vector<vector<int>> &ar,vector<int>&vs){
    vs[i]=1;
    for(int j=1;j<=n;j++){
        if(ar[i][j]&&!vs[j]){
            dfs(j,ar,vs);
        }
    }
}
bool lienthong(vector<vector<int>>& ar,vector<int> &vs){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            dfs(i,ar,vs);
            cnt++;
        }
        if(cnt>1) return false;
    }
    return true;
}
int check(vector<vector<int>> &ar,int top){
    for(int j=1;j<=n;j++){
        if(ar[top][j]){
            return j;
        }
    }
    return 0;
}
vector<int> euler(int i,vector<vector<int>> &ar){
    vector<int> ce;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
        int top=st.top();
        int sodau=check(ar,top);
        if(sodau){
            st.push(sodau);
            ar[top][sodau]=0;
            ar[sodau][top]=0;
        }else{
            ce.push_back(top);
            st.pop();
        }
    }
    return ce;
}
int main(){
    cin>>n>>st;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<int> vs(n+1,0);
    vector<int> deg(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
            if(ar[i][j]){
                deg[i]++;
                deg[i]++;
                if(i!=j) deg[j]++;
            }
        }
    }
    int cnt=0;
    for(auto v:deg){
        if(v%2!=0){
            cnt++;
        }
    }
    if(!lienthong(ar,vs)||(cnt!=0&&cnt!=2)){
        cout<<"no Euler cycle"<<endl;
    }else{
            vector<int> t4em=euler(st,ar);
            for(int i=t4em.size()-1;i>=0;i--){
                cout<<t4em[i]<<" ";
            }
        }
    return 0;
}