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
    int n, x = 0;
    cin>>n;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
        arr[i] /= 100;
        x += arr[i];
    }
    vector<bool> dp(n + 1);
    dp[0] = true;
    if(x % 2 != 0) cout<<"NO"<<endl;
    else{
        x /= 2;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j <= x; j++){
                if(j >= arr[i]) dp[j] = dp[j] || dp[j - arr[i]];
            }
        }
        if(dp[x]) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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