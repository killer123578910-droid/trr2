#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> temp;
void bfs(int i,vector<vector<int>> &ar,vector<int> &vs){
    vs[i]=1;
    queue<int> q;
    q.push(i);
    while(!q.empty()){
        int fr=q.front();q.pop();
        temp.push_back(fr);
        for(int j=1;j<=n;j++){
            if(ar[fr][j]&&!vs[j]){
                q.push(j);
                vs[j]=1;
            }
        }
    }
}
int main(){
    ifstream in("TK.INP");
    ofstream out("TK.OUT");
    in>>n;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<int>vs(n+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in>>ar[i][j];
        }
    }
    vector<vector<int>> lienthong;
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            bfs(i,ar,vs);
            sort(temp.begin(),temp.end());
            lienthong.push_back(temp);
            temp.clear();
        }
    }
    out<<lienthong.size()<<endl;
    for(auto x:lienthong){
        for(auto k:x){
            out<<k<<" ";
        }
        out<<endl;
    }
    return 0;
}