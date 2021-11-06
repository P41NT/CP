#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

int n, m, k, s;

void dfs(pair<int, int> i, vector< vector < bool> > &visited, const vector< vector< char > > &arr){
    if(visited[i.first][i.second] || arr[i.first][i.second] == '#' ) return;
    // if(k == 0) return;
    // cout<<s - k<< " ";
    if(s - k == 0) return;
    visited[i.first][i.second] = true; s--;
    if(i.first > 0) dfs(make_pair(i.first - 1, i.second), visited, arr);
    if(i.first < n - 1) dfs(make_pair(i.first + 1, i.second), visited, arr );
    if(i.second > 0) dfs(make_pair(i.first, i.second - 1), visited, arr);
    if(i.second < m - 1) dfs(make_pair(i.first, i.second + 1), visited, arr);
}

void solve(){
    //code goes here
    cin>>n>>m>>k;
    s = 0;
    vector< vector<char> > arr(n, vector<char> (m));
    pair<int, int> root;
    for(int i = 0;i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == '.') {
                root = make_pair(i, j);
                s++;
            }
        }
    }
    vector< vector< bool> > visited(n, vector< bool > (m));
    dfs(root, visited, arr);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '.' && !visited[i][j])
                cout<<'X';
            else cout<<arr[i][j];
        }
        cout<<endl;
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