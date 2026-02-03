#include<bits/stdc++.h>
using namespace std;
int n=10;
int ar[10][10];
vector<bool> b(10,false);
void dfs(int i){
    b[i]=true;
    cout<<i<<" ";
    for(int j=0;j<n;j++){
        if(ar[i][j]&&!b[j]){
            dfs(j);
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>ar[i][j];
        }
    }
    dfs(1);
    return 0;
}