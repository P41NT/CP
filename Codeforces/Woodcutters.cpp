#include <bits/stdc++.h>

using namespace std;
#define int long long int

int32_t main(){
    int n;
    cin>>n;
    vector<int> x(n+5);
    vector<int> h(n+5);
    vector<vector<int> > dp(n+5, vector<int>(5));
    for(int i = 1; i <= n; i++){
        cin>>x[i]>>h[i];
    }
    dp[1][1] = 1;
    if(x[1] + h[1] < x[2])
        dp[1][2] = 1;
    for(int i = 2; i <= n; i++){
        //save trees ;-;
        dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
        //cut to the left boi
        if(x[i] - h[i] > x[i-1] + h[i-1]){
            dp[i][1] = dp[i][0] + 1;
        }
        else if(x[i] - h[i] > x[i-1]){
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]) + 1;
        }
        //cut to the right boi
        if(i < n && x[i] + h[i] < x[i+1]){
            dp[i][2] = dp[i][0] + 1;
        }
        //last case
        if(i == n){
            dp[i][2] = dp[i][0] + 1;
        }
    }
    cout<<max(dp[n][0], max(dp[n][1], dp[n][2]));
}