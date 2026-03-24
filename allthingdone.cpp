#include<bits/stdc++.h>
using namespace std;
int n,v;
void reset(vector<int> &vs){
    fill(vs.begin(),vs.end(),0);
}
int dfs(int i,vector<vector<int>> &ar,vector<int>&vs){
    int cnt=1;
    stack<int> st;
    st.push(i);
    vs[i]=1;
    while(!st.empty()){
        int top=st.top();st.pop();
        for(int j=1;j<=n;j++){
            if(ar[top][j]&&!vs[j]){
                cnt++;
                st.push(top);
                st.push(j);
                break;
            }
        }
    }
    return cnt;
}
void bfs(int i,vector<vector<int>> &ar,vector<int>&vs){
    queue<int>q;
    q.push(i);
    vs[i]=1;
    while(!q.empty()){
        int front=q.front();q.pop();
        cout<<front<<" ";
        for(int j=1;j<=n;j++){
            if(ar[front][j]&&!vs[j]){
                vs[j]=0;
                q.push(j);
            }
        }
    }
}
bool lienthong(vector<vector<int>>& ar,vector<int> &vs){
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!vs[i]){
            dfs(i,ar,vs);
            cnt++;
        }
        if(cnt>1) return false;
    }
    return true;
}
void dinhtru(vector<vector<int>>&ar,vector<int> &vs){
    int tieuchuan=dfs(1,ar,vs);
    reset(vs);
    for(int i=1;i<=n;i++){
        vs[i]=false;
        int temp= dfs(i,ar,vs);
        if(temp>tieuchuan) cout<<i<<" ";
    }
}
void canhcau(vector<vector<int>> &ar,vector<int> &vs){
    int tieuchuan=dfs(1,ar,vs);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(ar[i][j]){
                ar[i][j]=0;ar[j][i]=0;
                reset(vs);
                int temp=dfs(1,ar,vs);
                if(temp>tieuchuan){
                    cout<<min(i,j)<<" "<<max(i,j)<<endl;
                }
            }
        }
    }
}
int check(vector<vector<int>>&ar,int top){
    for(int i=1;i<=n;i++){
        if(ar[top][i]){
            return i;
        }
    }
    return 0;
}
vector<int> chutrinheuler(int i,vector<vector<int>>&ar){
    vector<int> ce;
    stack<int> st;
    st.push(i);
    while(!st.empty()){
        int top=st.top();
        int sodau=check(ar,top);
        if(sodau){
            st.push(sodau);
            ar[sodau][top]=0;
            ar[top][sodau]=0;
        }else{
            ce.push_back(top);
            st.pop();
        }
    }
    return ce;
}
void hail(int k,vector<vector<int>> &ar,vector<int> &vs,vector<int> &x){
    for(int i=1;i<=n;i++){
        if(ar[x[k-1]][i]){
            if(k==n+1&&i==v){
                for (int t = 1; t <= n; t++)
                {
                    cout << x[t] << " ";
                }
                cout <<k<<endl;
            }else if(!vs[i]){
                x[k]=i;
                vs[i]=1;
                hail(k+1,ar,vs,x);
                vs[i]=0;
            }
        }
    }
}

int main(){
    cin >> n >> v;
    vector<vector<int>> ar(n + 1, vector<int>(n + 1, 0));
    vector<int> vs(n + 1, 0), x(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> ar[i][j];
        }
    }
}