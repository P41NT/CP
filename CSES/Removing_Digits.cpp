#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define INF INT_MAX 

void solve(){
    //code goes here
    int n; cin>>n;
    vector<int> dp(n + 1, 0);
    int dup, dig;
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        set<int> digits;
        dup = i;
        while(dup > 0){
            dig = dup%10;
            digits.insert(dig);
            dup /= 10;
        }
        dp[i] = INF;
        for(auto dig: digits){
            dp[i] = min(dp[i], 1 + dp[i - dig]);
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