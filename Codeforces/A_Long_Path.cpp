#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define MOD 1000000007

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    vector<int> dp(n + 2);
    for(int i = 1; i <= n; i++){
        dp[i + 1] = (dp[i] * 2 - dp[arr[i]] + 2 + MOD) % MOD;
    }
    cout<<dp[n + 1];
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