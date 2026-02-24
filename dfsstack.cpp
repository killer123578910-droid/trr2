#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>> ar(n+1,vector<int>(n+1));
    vector<bool> visite(n+1,false);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ar[i][j];
        }
    }
    stack<int> st;
    st.push(1);
    cout<<1<<" ";
    visite[1]=true;
    while(!st.empty()){
        int u=st.top();st.pop();
            for(int k=1;k<=n;k++){
                if(ar[u][k]&&!visite[k]){
                    visite[k]=true;
                    cout<<k<<" ";
                    st.push(u);
                    st.push(k);
                    break;
                }
            }
        }
        return 0;
}
   