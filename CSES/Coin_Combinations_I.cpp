#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

const int MOD = (int) 1e9 + 7;

void solve(){
    //code goes here
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        for(int k = 0; k < n; k++){
            if(i - arr[k] >= 0 ) dp[i] += dp[i - arr[k]] % MOD;
            dp[i] %= MOD;
        }
    }
    cout<<dp[x]<<endl;
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