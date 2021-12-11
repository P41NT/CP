#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    int m = 0;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        m += arr[i];
    }
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = dp[i-1][j];
            if(j - arr[i] >= 0) dp[i][j] = dp[i][j] || dp[i-1][j - arr[i]];
        }
    }
    set<int> ans;
    for(int i = 1; i <= m; i++){
        if(dp[n][i]) ans.insert(i);
    }
    cout<<ans.size()<<endl;
    for(int a : ans) cout<<a<<" ";
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