#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)

void dfs(int i , vector<int> G[], vector<int>& visited){
    if(visited[i]) return;
    visited[i] = 1;
    for(int cnode : G[i]){
        if(!visited[cnode])
            dfs(cnode, G, visited);
    }
}

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<int> G[n + 1];
    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> visited(n + 2, 0);
    vector<int> islands;
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            islands.push_back(i);
            dfs(i, G, visited);
        }
    }
    cout<<islands.size()-1<<endl;
    for(int i = 1; i < islands.size(); i++){
        cout<<islands[i-1]<<" "<<islands[i]<<endl;
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