#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> prices(n + 1);
    for(int i = 1; i <= n; i++)
        cin>>prices[i];
    sort(prices.begin() + 1, prices.end(), greater<int>());
    int ans = 0;
    for(int i= 1 ; i <= n; i++){
        ans = max(ans, prices[i] * i);
        // cout<<prices[i]<<" ";
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