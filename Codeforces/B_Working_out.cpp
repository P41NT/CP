#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<vector<int>> arr(n + 1, vector<int>(m + 1));
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            cin>>arr[i][j];
        }
    }
    
    vector<vector<int>> dp1(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp2(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp3(n + 2, vector<int>(m + 2));
    vector<vector<int>> dp4(n + 2, vector<int>(m + 2));
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp1[i][j] = arr[i][j] + max(dp1[i-1][j], dp1[i][j-1]);
    for(int i = n; i >= 1; i--)
        for(int j = m; j >= 1; j--)
            dp2[i][j] = arr[i][j] + max(dp2[i+1][j], dp2[i][j+1]);
    for(int i = n; i >= 1; i--)
        for(int j = 1; j <= m; j++)
            dp3[i][j] = arr[i][j] + max(dp3[i+1][j], dp3[i][j-1]);
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= 1; j--)
            dp4[i][j] = arr[i][j] + max(dp4[i-1][j], dp4[i][j+1]);
    int ans = 0; 
    for(int i = 2; i <= n-1; i++){
        for(int j = 2; j <= m-1; j++){
            ans = max(ans, dp1[i-1][j] + dp2[i+1][j] + dp4[i][j+1] + dp3[i][j-1]);
            ans = max(ans, dp1[i][j-1] + dp2[i][j+1] + dp4[i-1][j] + dp3[i+1][j]);
        }
    }
    cout<<ans<<endl;

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //============================================
    int t;
    t = 1;
    //cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}