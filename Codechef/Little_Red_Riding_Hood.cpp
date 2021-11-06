#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<vector<int> > arr(n + 1, vector<int> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<bool> > safe(n + 1, vector<bool> (n + 1));
    for(int i = 0; i < m; i++){
        int x, y, k;
        cin>>x>>y>>k;
        for(int i = -k; i <= k; i++){
            for(int j = abs(i) -k; j <= k - abs(i); j++){
                if(x + i >= 1 && x + i <= n && y + j >= 1 && y + j <= n ){
                    safe[x + i][y + j] = true;
                }
            }
        }
    }
    vector<vector<int> > dp(n + 1, vector<int> (n + 1, LONG_MIN));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(safe[i][j]){
                if(i > 1 && dp[i-1][j] != LONG_MIN) dp[i][j] = max(dp[i][j], dp[i-1][j] + arr[i][j]);
                if(j > 1 && dp[i][j-1] != LONG_MIN) dp[i][j] = max(dp[i][j], dp[i][j-1] + arr[i][j]);
                else if(i == 1 && j == 1) dp[i][j] = arr[i][j];
            }
        }
    }
    if(dp[n][n] != LONG_MIN){
        cout<<"YES"<<endl<<dp[n][n];
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

// 8838470784