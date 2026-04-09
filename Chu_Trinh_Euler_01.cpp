#include<bits/stdc++.h>
using namespace std;

int n, m, start;

// lấy 1 đỉnh kề bất kỳ
int check(vector<set<int>> &ar, int top){
    if(!ar[top].empty()){
        return *ar[top].begin();
    }
    return 0;
}

// tìm đường đi / chu trình Euler
vector<int> euler(int i, vector<set<int>> &ar){
    vector<int> ce;
    stack<int> st;
    st.push(i);

    while(!st.empty()){
        int top = st.top();
        int sodau = check(ar, top);

        if(sodau){
            st.push(sodau);
            ar[top].erase(sodau);
            ar[sodau].erase(top);
        }else{
            ce.push_back(top);
            st.pop();
        }
    }
    return ce;
}

// kiểm tra liên thông (bỏ đỉnh cô lập)
bool lienThong(vector<set<int>> &ar){
    vector<bool> visited(n+1,false);
    queue<int> q;

    int s = -1;
    for(int i=1;i<=n;i++){
        if(!ar[i].empty()){
            s = i;
            break;
        }
    }

    if(s == -1) return true; // không có cạnh

    q.push(s);
    visited[s] = true;

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(int v : ar[u]){
            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }

    for(int i=1;i<=n;i++){
        if(!ar[i].empty() && !visited[i]) return false;
    }
    return true;
}

int main(){
    int t;
    cin >> t;

    if(t == 1){
        cin >> n >> m;
        vector<set<int>> ar(n+1);

        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            ar[x].insert(y);
            ar[y].insert(x);
        }

        if(!lienThong(ar)){
            cout << 0;
            return 0;
        }

        int demLe = 0;
        for(int i=1;i<=n;i++){
            if(ar[i].size() % 2 != 0){
                demLe++;
            }
        }

        if(demLe == 0) cout << 1;      // Euler
        else if(demLe == 2) cout << 2; // Nửa Euler
        else cout << 0;

    } 
    else if(t == 2){
        cin >> n >> m >> start;
        vector<set<int>> ar(n+1);

        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            ar[x].insert(y);
            ar[y].insert(x);
        }

        vector<int> res = euler(start, ar);

        for(int i = res.size()-1; i >= 0; i--){
            cout << res[i] << " ";
        }
    }
}