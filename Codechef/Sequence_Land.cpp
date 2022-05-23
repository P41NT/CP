#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

int n, k;
int ans = 0;

bool ok(vector<int> a, vector<int> b){
    int count = 0;
    for(int item : a){
        if(binary_search(b.begin(), b.end(), item)){
            count++;
        }
    }
    return count >= k;
}

void dfs(int i, vector<int> G[], vector<bool> &visited){
    if(visited[i]) return;
    visited[i] = true;
    ans++;
    for(int cnode : G[i]){
        dfs(cnode, G, visited);
    }
}

void solve(){
    //code goes here
    cin>>n>>k;
    vector<vector<int> > data(n);
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        for(int j = 0; j < temp; j++){
            int temp1;
            cin>>temp1;
            data[i].push_back(temp1);
        }
        sort(data[i].begin(), data[i].end());
    }
    vector<int> G[n];
    vector<bool> visited(n);
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(ok(data[i], data[j])){
                G[i].push_back(j);
                G[j].push_back(i);
            }
        }
    }
    dfs(0, G, visited);
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