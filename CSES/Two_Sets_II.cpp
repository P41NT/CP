#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"


const int MOD =  (int) 1e9 + 7;

void solve(){
    //code goes here
    int n;
    cin>>n;
    int m = n * (n + 1) / 2;
    if(m%2){
        cout<<0<<endl;
        return;
    }
    m/= 2;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++) cin>>arr[i];
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j - i >= 0){
                dp[i][j] += dp[i-1][j - i];
                dp[i][j] %= MOD;
            }
        }
    }
    // for(int j = 0; j <= m; j++){
    //     for(int i = 0; i <= n; i++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][m];
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