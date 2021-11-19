#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define mod 1000000007

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> dp(n + 1);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= 6; j++){
            if(i -j >= 0){
                dp[i] += dp[i-j] % mod;
                dp[i] %= mod;
            }
        }
    }
    cout<<dp[n]<<endl;
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