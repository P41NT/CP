#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

bool dfs(int u, int v, vector<bool> &visited, const vector<pair<int, int>> G[], int col){
    visited[u] = true;
    if(u == v) return true;
    for(pair<int, int> cnode : G[u]){
        if(cnode.second == col && !visited[cnode.first]){
            if(dfs(cnode.first, v, visited, G, col)) return true;
        }
    }
    return false;
}

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<pair<int, int>> G[n];
    vector<bool> visited(n);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        a--; b--;c--;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }
    int q; cin>>q;
    int ans;
    int u, v;
    while(q--){
        ans = 0;
        cin>>u>>v;
        u--;v--;
        // cout<<"color";
        for(int col = 0; col <= 100; col++){
            // cout<<" "<<col<<":"<<ans<<" ";
            for(int i = 0; i < n; i++) visited[i] = false;
            if(dfs(u, v, visited, G, col)) ++ans;
        }
        cout<<ans<<endl;
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