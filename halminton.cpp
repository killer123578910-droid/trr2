#include<bits/stdc++.h>
using namespace std;

int n, v;
vector<vector<int>> ans;

void halminton(int k, vector<vector<int>>& ar, vector<bool>& vs, vector<int>& x){
    for(int i = 1; i <= n; i++){
        if(ar[x[k-1]][i]){
            if(k == n+1 && i == v){
                vector<int> temp;
                for(int j = 1; j <= n; j++) temp.push_back(x[j]);
                temp.push_back(v);
                ans.push_back(temp);
            }
            else if(!vs[i]){
                x[k] = i;
                vs[i] = true;
                halminton(k+1, ar, vs, x);
                vs[i] = false;
            }
        }
    }
}

int main(){
    cin >> n >> v;
    vector<vector<int>> ar(n+1, vector<int>(n+1));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> ar[i][j];
        }
    }

    vector<bool> vs(n+1, false);
    vector<int> x(n+1);

    x[1] = v;
    vs[v] = true;

    halminton(2, ar, vs, x);

    for(auto &k : ans){
        for(auto &i : k){
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
