#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define end "\n"

void dfs(int curr, int parent, const vector<int> G[], vector<int> &visited){
    int len = visited.size();
    cout<<len<<" ";
    int ans = 1;
    // for(int cnode : G[curr]){
    //     if(cnode != parent){
    //         while(ans == visited[curr] || ans == visited[parent]) ans ++;
    //         visited[cnode] = ans;
    //         dfs(cnode, curr, G, visited);
    //         ans++;
    //     }
    // }
}

void solve(){
    //code goes here
    int n; cin>>n;
    vector<int> G[n];
    for(int i = 1; i < n; i++){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> visited(n + 1,1);
    dfs(1, 1, G, visited);
    int sol = 0;
    for(int ans : visited){
        sol = max(sol, ans);
    }
    cout<<sol<<endl;
}

int32_t main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    //================================================================
    int t;
    //t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}