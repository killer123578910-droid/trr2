#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
    int t;cin>>t;
    cin>>n;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<pair<int,int>> canh;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
            if(ar[i][j]&&i<j){
                canh.push_back({i,j});
            }
        }
    }
    if(t==1){
        for(int i=1;i<=n;i++){
            int temp=0;
            for(int j=1;j<=n;j++){
                temp+=ar[i][j];
            }
            cout<<temp<<" ";
        }
    }else{
        cout<<n<<" "<<canh.size()<<endl;
        for(auto x:canh){
            cout<<min(x.first,x.second)<<" "<<max(x.first,x.second)<<endl;
        }
    }
}