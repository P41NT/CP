#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, m, l, k;

int dfs(int u, int t, map<int, pair<int, int>> &turning_point, const vector<int> &happiness, const vector<pair<int, int>> G[], int curr_score, vector<bool> &visited){
    // cout<<u<<" "<<t<<" "<<curr_score<<endl;
    // if(u == 0) cout<<"-----"<<endl;
    if(t > l) return -1;
    if(turning_point.count(u) && turning_point[u].first == t) curr_score += turning_point[u].second;
    // if(turning_point.count(u) ) curr_score += turning_point[u].second;
    curr_score += happiness[u];
    // cout<<curr_score<<" ";
    if(u == 0 && t == l) return curr_score;
    // if(t == l) return -1;
    int temp = 0;
    for(pair<int, int> v : G[u]){
        temp = max(temp, dfs(v.first, t + v.second, turning_point, happiness, G, curr_score , visited));
    }
    // cout<<temp<<" ";
    return temp;
}

void solve(){
    //code goes here
    cin>>n>>m>>l>>k;
    vector<int> happiness(n);
    // vector<vector<> turning_point(k, vector<int>(3));
    map<int, pair<int, int>> turning_point;
    vector<pair<int, int>> G[n];
    vector<bool> visited(n);
    for(int i = 0; i < n; i++){
        cin>>happiness[i];
    }
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin>>u>>v>>w;
        u--; v--;
        G[u].push_back({v, w});
    }
    for(int i = 0; i < k; i++){
        cin>>u>>v>>w;
        v--;
        turning_point.insert({v, {u, w}});
        // turning_point[i] = {u, v, w};
    }
    int ans = dfs(0, 0, turning_point, happiness, G, 0, visited);
    if(ans <= 0) cout<<-1<<endl;
    else cout<<ans<<endl;
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