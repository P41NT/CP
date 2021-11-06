#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


int n, m, s ,t ;

vector<int> bfs(int u, vector<int> G[]){
    vector<int> d(n, -1);
    d[u] = 0;
    queue<int> q;
    q.push(u);
    while(!q.empty()){
        int a = q.front(); q.pop();
        for(int cnode : G[a]){
            if(d[cnode] == -1){
                d[cnode] = d[a] + 1;
                q.push(cnode);
            }
        }
    }
    return d;
}

void solve(){
    //code goes here
    cin>>n>>m>>s>>t;
    s--; t--;
    vector<int> G[n];
    vector<vector<bool> > edge_list(n, vector<bool>(n));
    for(int i = 0;i < m;i++){
        int u, v;
        cin>>u>>v;
        u--;v--;
        G[v].push_back(u);
        G[u].push_back(v);
        edge_list[u][v] = true;
    }
    vector<int> s_distances = bfs(s, G);
    vector<int> t_distances = bfs(t, G);
    int D = s_distances[t];
    int ans = 0;
    for(int i = 0; i < n -1; i++){
        for(int j = i + 1; j < n; j++){
            if(i != j && !edge_list[i][j]){
                if(s_distances[i] + t_distances[j] + 1 >= D && t_distances[i] + s_distances[j] + 1 >= D) ans++;
            }
        }
    }
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