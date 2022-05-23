#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

const int MOD = (int) 1e9 + 7;

void solve(){
    int n;
    cin>>n;
    vector<vector<char>> arr(n + 1, vector<char> (n + 1));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin>>arr[i][j];
        }
    }
    // for(auto v : arr){
    //     for(auto s : v)
    //         cout<<s<<" ";
    //     cout<<endl;
    // }
    vector<vector<int>> dp(n + 1, vector<int> (n + 1));
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(arr[i][j] == '*') dp[i][j] = 0;
            else{
                if(i > 1) dp[i][j] += dp[i-1][j];
                if(j > 1) dp[i][j] += dp[i][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    cout<<dp[n][n]<<endl;
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