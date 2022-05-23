#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void dfs_get_nodes(int i, int &count, int &mini, int &maxi, vector<bool> &visited, const vector<int> G[]){
    if(visited[i]) return;
    visited[i] = true;

    mini = min(mini, i);
    maxi = max(maxi, i);
    count++;
    for(int cnode : G[i]){
        dfs_get_nodes(cnode, count, mini, maxi, visited, G);
    }
}

void dfs_get_sum(int i, int &sum, vector<bool> &visited, const vector<int> G[], int level){
    if(visited[i]) return;
    visited[i] = true;
    sum += level;
    for(int cnode : G[i]){
        dfs_get_sum(cnode,sum, visited, G, level + 1);
    }
}

void solve(){
    //code goes here
    int n, m;
    int u, v;
    int count, maxi, mini;
    cin>>n>>m;
    vector<int> G[n];
    vector<bool> visited(n);
    vector<int> roots1;
    vector<int> roots2;
    for(int i = 0;i < m; i++){
        cin>>u>>v;
        u--;v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 0;i < n; i++){
        count = 0;
        maxi = -1e5;
        mini = 1e5;
        if(visited[i]) continue;
        dfs_get_nodes(i, count, mini, maxi, visited, G);
        if(count%2 == 0) roots1.push_back(mini);
        else roots2.push_back(maxi);
    }
    for(int i = 0;i < n; i++) visited[i] = false;
    int ans1, ans2;
    ans1 = ans2 = 0;
    for(int root : roots1){
        dfs_get_sum(root, ans1, visited, G, 1);
    }
    cout<<endl;
    for(int root : roots2){
        dfs_get_sum(root, ans2, visited, G, 1);
    }
    cout<<ans1<<" "<<ans2<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    // t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}