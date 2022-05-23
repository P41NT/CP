#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define INF 1e9

void solve(){
    int n, x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    vector<int> dp(x + 1, INF);
    dp[0] = 0;
    for(auto &coin : arr){
        for(int i = 1; i <= x; i++){
            if(i >= coin) dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
    if(dp[x] == INF) cout<<"-1"<<endl;
    else cout<<dp[x]<<endl;
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