#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)
#define loop(i, l, j, h) for(int i = l; i <= j; h)

void dfs(int i , vector<int> G[], vector<int> &visited, vector<int> &closed, int &connected_components){
    if(visited[i] || closed[i]) return;
    connected_components++;
    visited[i] = 1;
    for(int cnode : G[i]){
        if(!visited[cnode]) 
            dfs(cnode, G, visited, closed, connected_components);
    }
}

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<int> G[n + 1];
    forj(i, m){
        int a, b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> order(n+1);
    forj(i, n){
        cin>>order[i+1];
    }
    vector<int> visited(n + 1);
    vector<int> closed(n + 1);
    int connected_components = 0;
    dfs(1, G, visited, closed, connected_components);
    if(connected_components == n) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    for(int i = 1; i < n; i++){
        fill(visited.begin(), visited.end(), 0);
        connected_components = 0;
        closed[order[i]] = 1;
        dfs(order[n], G, visited, closed, connected_components);
        if(connected_components == n - i) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
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