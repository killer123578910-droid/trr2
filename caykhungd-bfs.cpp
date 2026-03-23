#include<bits/stdc++.h>
using namespace std;
int n,k;
void dfs(int i,vector<vector<int>> &ar,vector<int> &vs){
    vs[i]=1;
    for(int j=1;j<=n;j++){
        if(ar[i][j]&&!vs[j]){
            cout<<min(i,j)<<" "<<max(i,j)<<endl;
            dfs(j,ar,vs);
        }
    }
}
void bfs(int i,vector<vector<int>> &ar,vector<int> &vs){
    queue<int> q;
    q.push(i);
    vs[i]=1;
    while(!q.empty()){
        int pa=q.front();
        q.pop();
        for(int j=1;j<=n;j++){
            if(ar[pa][j]&&!vs[j]){
                cout<<min(pa,j)<<" "<<max(pa,j)<<endl;
                q.push(j);
                vs[j]=1;
            }
        }
    }
}
int main(){
    cin >> n>>k;
    vector<vector<int>> ar(n + 1, vector<int>(n + 1, 0));
    vector<int> vs(n+1,0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }
    cout<<"DFS tree:"<<endl;
    dfs(k,ar,vs);
    fill(vs.begin(),vs.end(),0);
    cout<<"BFS tree:"<<endl;
    bfs(k,ar,vs);
    return 0;
}