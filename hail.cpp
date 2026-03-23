#include<bits/stdc++.h>
using namespace std;
int n,v;
vector<vector<int>> ans;
void hail(int k,vector<vector<int>> &ar,vector<int>&vs,vector<int>&x){
    for(int i=1;i<=n;i++){
        if(ar[x[k-1]][i]){
            if(k==n+1 &&i==v){
                vector<int> temp;
                for(int j=1;j<=n;j++) temp.push_back(x[j]);
                temp.push_back(v);
                ans.push_back(temp);
            }
            else if(!vs[i]){
                x[k]=i;
                vs[i]=1;
                hail(k+1,ar,vs,x);
                vs[i]=0;
            }
        }
    }
}
int main(){
    cin>>n>>v;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<int> vs(n+1,0);
    vector<int> x(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    x[1]=v;
    vs[v]=1;
    hail(2,ar,vs,x);
    for(auto &k : ans){
        for(auto &i : k){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}