#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define adjList(name, n) vector<int> name[n]

void dfs(int node, const vector<int> G[], vector<bool>& visited ){
    visited[node] = true;
    for(auto cnode : G[node]){
       dfs(cnode, G, visited);
    }
}

bool okay(const vector<bool>& visited) {
    for(bool i : visited) {
        if(!i) return false;
    }
    return true;
}

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> G[n];
    for(int i = 0; i< n-1 ;i++){
        int a, b;
        cin>>a>>b;
        a--, b--;
        G[b].push_back(a);
    }
    vector<bool> visited(n);
    bool flag = false;
    for(int i = 0; i< n; i++){
        fill(visited.begin(), visited.end(), false);
        dfs(i, G, visited);
        if(okay(visited)){
            cout<<i + 1<<endl;
            flag = true;
            break;
        }
    }
    if(!flag){
        cout<<-1<<endl;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}