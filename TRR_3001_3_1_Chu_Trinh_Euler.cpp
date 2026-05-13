#include <bits/stdc++.h>
using namespace std;
int n;
int checke(int t,vector<vector<int>>&ar){
    for(int i=1;i<=n;i++){
        if(ar[t][i]){
            return i;
        }
    }
    return 0;
}
void dfs(int i,vector<vector<int>> &ar,vector<int>&vs){
    vs[i]=1;
    for(int j=1;j<=n;j++){
        if(ar[i][j]&&!vs[j]){
            dfs(j,ar,vs);
        }
    }
}
int main()
{
    int t;
    ifstream in("CT.INP");
    ofstream out("CT.OUT");
    in >> t;
    if (t == 1)
    {   
        in>>n;
        vector<vector<int>> ar(n + 1, vector<int>(n + 1));
        vector<int> bac(n + 1),vs(n+1,false);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                in >> ar[i][j];
                bac[i] += ar[i][j];
            }
        }
        dfs(1,ar,vs);
        for(int i=1;i<=n;i++){
            if(!vs[i]){
                out<<0;
                return 0;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            if (bac[i] % 2 != 0)
            {
                cnt++;
            }
            if (cnt > 2)
            {
                out << 0;
                return 0;
            }
        }
        if (cnt == 2)
        {
            out << 2;
        }
        else
        {
            out << 1;
        }
    }
    else
    {   
        int u;
        in>>n>>u;
        vector<vector<int>> ar(n+1,vector<int>(n+1));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                in>>ar[i][j];
            }
        }
        stack<int> st;
        vector<int> kq;
        st.push(u);
        while(!st.empty()){
            int t=st.top();
            int k=checke(t,ar);
            if(k){
                st.push(k);
                ar[t][k]=0;
                ar[k][t]=0;
            }else{
                st.pop();
                kq.push_back(t);
            }
        }
        for(int i=kq.size()-1;i>=0;i--){
            out<<kq[i]<<" ";
        }
    }
}