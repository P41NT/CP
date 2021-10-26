#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    vector<int> dp(n + 3);
    int total = 0;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
        total += arr[i];
    }
    for(int i = 0; i < 3; i++){
        dp[i] = arr[i];
    }
    for(int i = 3; i <= n; i++){
        dp[i] = arr[i] + min(dp[i-1], min(dp[i-2], dp[i-3]));
    }
    cout<<total - dp[n]<<endl;
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