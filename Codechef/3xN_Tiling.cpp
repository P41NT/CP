#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int k, n;
    cin>>k>>n;
    if(k == 1){
        int ans = n%3?0:1;
        cout<<ans<<endl;
    }
    if(k == 2){
        vector<int> dp(n + 1);
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 1;
        for(int i = 4; i <= n; i++){
            dp[i] = dp[i-2] + dp[i-3];
        }
        cout<<dp[n]<<endl;
    }
    if(k == 3){
        if(n < 3) cout<<1<<endl;
        else {
            vector<vector<int>> dp(3, vector<int>(n + 1));
            dp[0][1] = 1;
            dp[0][2] = 1;
            dp[0][3] = 2;
            dp[1][1] = 0;
            dp[1][2] = 0;
            dp[1][3] = 0;
            dp[2][1] = 0;
            dp[2][2] = 0;
            dp[2][3] = 1;

            for(int i = 4; i <= n; i++){
                dp[0][i] = (2 * dp[1][i-2]) + dp[0][i-3] + dp[0][i-1];
                dp[1][i] = dp[1][i-3] + dp[2][i-1];
                dp[2][i] = dp[2][i-3] + dp[0][i-3];
            }
            cout<<dp[0][n]<<endl;
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    // t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}