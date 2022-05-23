#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod 1000000007

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<vector<int>> dp(n + 1, vector<int>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= n; i++){
        dp[i][0] = (dp[i-1][0] * 2 + dp[i-1][1] )%mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 4)%mod;
    }
    cout<<(dp[n][0] + dp[n][1])%mod<<endl;
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