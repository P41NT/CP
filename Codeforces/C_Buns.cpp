#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n, m, c0, d0;
    cin>>n>>m>>c0>>d0;
    vector<int> a(m + 1);
    vector<int> b(m + 1);
    vector<int> c(m + 1);
    vector<int> d(m + 1);

    for(int i = 1; i <= m; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            for(int k = 0; k <= a[j]/b[j]; k++){
                if(i - c[j] * k >= 0)
                    dp[i][j] = max(dp[i][j], dp[i - c[j] * k][j - 1] + d[j] * k);
            }
        }
    }
    int ans = 0;
    for(int k = 0; k <= n; k++){
        ans = max(ans, dp[k][m] + (n-k)/c0 * d0);
    }
    cout<<ans<<endl;
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