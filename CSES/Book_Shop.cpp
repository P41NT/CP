#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)
#define loop(i, l, j, h) for(int i = l; i <= j; h)

void solve(){
    //code goes here
    int n, w;
    cin>>n>>w;
    vector<int> weight(n + 1), value(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>weight[i];
    }
    for(int i = 1; i <= n; i++){
        cin>>value[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(w));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= w; j++){
            dp[i][j] = dp[i-1][j];
            if(j - weight[i] >= 0)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
        }
    }
    cout<<dp[n][w];
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