#include<bits/stdc++.h>
using namespace std;
int n,d,c;
void dfs(int i,vector<vector<int>> ar,vector<bool> &vs,int n,vector<int> &parent){
    vs[i]=true;
    for(int j=1;j<=n;j++){
        if(ar[i][j]&&!vs[j]){
            parent[j]=i;
            dfs(j,ar,vs,n,parent);
        }
    }
}
void bfs(int i,vector<vector<int>> ar,vector<bool> &vs,int n,vector<int> &parent){
    queue<int> q;
    q.push(i);
    vs[i]=true;
    while(!q.empty()){
        int top=q.front();
        q.pop();
        for(int j=1;j<=n;j++){
            if(ar[top][j]&&!vs[j]){
                q.push(j);
                parent[j]=top;
                vs[j]=true;
            }
        }
        
    }
}
int main(){
    cin>>n;
    cin>>d>>c;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<bool> vs1(n+1,0),vs2(n+1,0);
    vector<int> parent1(n+1,0),parent2(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    dfs(d,ar,vs1,n,parent1);
    if(!vs1[c]) cout<<"No path"<<endl;
    else{
        cout<<"dfs: ";
        int temp=c;
        while(temp!=d){
            cout<<temp<<" ";
            temp=parent1[temp];
        }
        cout<<d<<endl;
        cout<<"bfs:";
        bfs(d,ar,vs2,n,parent2);
        temp=c;
        while(temp!=d){
            cout<<temp<<" ";
            temp=parent2[temp];
        }
        cout<<d;

    }
}