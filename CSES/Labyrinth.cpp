#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

pair<int, int> start;
pair<int, int> end_;

const int dy[5] = {-1, 0, 1, 0, -1};
const int dx[5] = {0, -1, 0, 1, 0};
const char dir[4] = {'L', 'U', 'R', 'D'};

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<vector<char>> arr(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin>>arr[i][j];
            if(arr[i][j] == 'A') start = {i, j};
            else if(arr[i][j] == 'B') end_ = {i, j};
        }
    }
    // cout<<start.first<<" "<<start.second<<endl;
    // cout<<end_.first<<" "<<end_.second<<endl;
    queue<pair<int, int>> q;
    vector<vector<int>> prev(n, vector<int>(m, 5));
    q.push(start);
    visited[start.first][start.second] = true;
    while(!q.empty()){
        pair<int, int> u = q.front(); q.pop();
        for(int i = 0; i < 4; i++){
            pair<int,int> v = {u.first + dx[i], u.second + dy[i] };
            if(v.first < 0 || v.second < 0 || v.first >= n || v.second >= m ) continue;
            if(arr[v.first][v.second] == '#') continue;
            // cout<<v.first<<" "<<v.second<<endl;
            if(visited[v.first][v.second]) continue;
            visited[v.first][v.second] = true;
            prev[v.first][v.second] = i;
            q.push(v);
        }
    }


    if(visited[end_.first][end_.second]){
        cout<<"YES"<<endl;
        vector<char> directions;
        auto cur = end_;
        while(cur != start){
            int x = prev[cur.first][cur.second];
            directions.push_back(x);
            cur = {cur.first - dx[x], cur.second - dy[x]};
        }
        // cout<<cur.first<<" "<<cur.second<<endl;
        reverse(directions.begin(), directions.end());
        cout<<directions.size()<<endl;
        for(int letter : directions) {
            cout<<dir[letter];
        }
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
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