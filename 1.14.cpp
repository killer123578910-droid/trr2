#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("DT.INP");
    ofstream out("DT.OUT");
    int t,n,m;
    in>>t>>n;
    m=0;
    vector<pair<int,int>> bac(n+1);
    vector<vector<int>> ar(n+1,vector<int>(n+1,0));
    vector<vector<int>> mt(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            in>>ar[i][j];
            if(ar[i][j]!=0){
                mt[i].push_back(j);
                m++;
                bac[i].second+=1;
                bac[j].first+=1;
            }
        }
    }
    vector<vector<int>> lt(n+1,vector<int>(m+1,0));
    if(t==1){
        for(int i=1;i<=n;i++){
            out<<bac[i].first<<" "<<bac[i].second<<endl;
        }
    }else{
        out<<n<<" "<<m<<endl;
        int k=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ar[i][j]){
                    lt[i][k]=1;
                    lt[j][k]=-1;
                    k++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                out<<lt[i][j]<<" ";
            }
            out<<endl;
        }
    }

    return 0;
}