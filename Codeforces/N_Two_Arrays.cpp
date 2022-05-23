#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)
#define loop(i, l, j, h) for(int i = l; i <= j; h)
#define MOD 1000000007

int sol(int n, int m){
    if(m == 0) return 1;
    int ans = 0;
    for(int k = 1; k <= n; k++){
        ans += sol(k, m - 1) * (n - k + 1);
    }
    return ans;
}

void solve(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++){
        dp[i][0] = 1;
    }
    for(int m_ = 1; m_ <= m; m_++){
        for(int n_ = 1; n_ <= n; n_++){
            for(int k = 1; k <= n_; k++){
                dp[n_][m_] += dp[k][m_-1] * (n_ - k + 1);
                dp[n_][m_] %= MOD;
            }
        }
    }
    cout<<dp[n][m];
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