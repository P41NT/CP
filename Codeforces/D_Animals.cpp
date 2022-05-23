#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        arr[i] *= (n - i + 1);
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i] >= 0)
                dp[i][j] = max(dp[i][j], dp[i - 1][j-arr[i]] + 1);
        }
    }
    // for(int j = 0; j <= m; j++){
    //     for(int i = 1; i <= n; i++){
    //         cout<<dp[i][j];
    //         cout<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n][m]<<endl;
}

int32_t main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

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