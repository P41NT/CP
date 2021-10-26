#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++)
        cin>>arr[i];
    
    vector<int> dp(n + 2), dp1(n + 2);
    dp[1] = arr[1];
    dp1[n] = arr[n];
    for(int i = 2; i <= n; i++){
        dp[i] = arr[i] + min(dp[i - 1], dp[i - 2]);
    }
    for(int i = n - 1; i >= 1; i--){
        dp1[i] = arr[i] + min(dp1[i + 1], dp1[i + 2]);
    }
    cout<<min(dp[n], dp1[1])<<endl;
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