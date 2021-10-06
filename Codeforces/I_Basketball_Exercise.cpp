#include <bits/stdc++.h>

using namespace std;

#define int long long int

int32_t main(){
    int n;
    cin>>n;
    vector<vector<int> > dp(2, vector<int>(n+1));
    vector<vector<int> > v(2, vector<int>(n+1));
    for(int i = 1; i <= n; i++){
        cin>>v[0][i];
    }
    for(int i = 1; i <= n; i++){
        cin>>v[1][i];
    }
    for(int i = 1; i <= n; i++){
        dp[0][i] = max(dp[0][i-1], dp[1][i-1] + v[0][i]);
        dp[1][i] = max(dp[1][i-1], dp[0][i-1] + v[1][i]);
    }
    cout<<max(dp[0][n], dp[1][n]);
}