#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

int n;
int ans;

void dfs(int i, const vector<int> G[], const vector<int> &a, vector<int> &diff){
    // visited[i] = true;
    int maxDiff = (int)-1e9;
    for(auto cnode : G[i]){
        maxDiff = max(maxDiff, a[i] - a[cnode]);
        // if(visited[cnode]) continue;
        dfs(cnode,G, a, diff);
        maxDiff = max(maxDiff, a[i] - a[cnode] + diff[cnode]);
    }
    diff[i] = maxDiff;
    ans = max(ans, maxDiff);
}

void solve(){
    //code goes here
    cin>>n;
    vector<int> a(n + 1);
    vector<int> G[n + 1];
    vector<int> differences(n + 1);

    for(int i = 0; i < n; i++) 
        cin>>a[i];

    int root = 0;
    for(int i = 0;i < n; i++){
        int parent;
        cin>>parent;
        if(parent == -1) root = i;
        else G[parent - 1].push_back(i);
    }
    dfs(root, G, a, differences);
    cout<<ans<<endl;
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