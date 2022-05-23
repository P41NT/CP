#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i < n; i++){
        cin>>v[i];
    }
    vector<vector<int> > dp(2, vector<int>(n));
    dp[0][0] = 1;
    dp[1][0] = 1;
    for(int i = 1;i < n; i++){
        if(v[i] > v[i-1]){
            dp[0][i] = dp[0][i-1] + 1;
            dp[1][i] = dp[1][i-1] + 1;
        }
        else{
            dp[0][i] = 1;
            dp[1][i] = 1;
        }
        if(i >= 2 && v[i] > v[i-2]) dp[1][i] = max(dp[1][i], dp[0][i-2] + 1);
    }
    int max_ = 0;
    for(int i = 0; i < n; i++) {
        max_ = max(max_, max(dp[1][i], dp[0][i]));
    }
    cout<<max_;
}

int32_t main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}
