#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[1][arr[1]] = 1;
    for(int i = 1; i <= n; i++){
        if(arr[i] == 0){
            for(int j = 1; j <= m; j++){
                dp[i][j] += dp[i-1][j];
                if(j - 1 > 0) dp[i][j] += dp[i-1][j-1];
                if(j + 1 <= m) dp[i][j] += dp[i-1][j+1];
            }
        }
        else{
            int j = arr[i];
            dp[i][j] += dp[i-1][j];
            if(j - 1 > 0) dp[i][j] += dp[i-1][j-1];
            if(j + 1 <= m) dp[i][j] += dp[i-1][j+1];
        }
    }
    int ans = 0;
    for(int i = 1; i<= m; i++){
        ans += dp[n][i];
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