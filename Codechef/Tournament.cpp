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
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    int ans = 0;
    for(int i = 0 ; i < n; i++){
        for(int j = i + 1; j < n; j++){
            ans += abs(arr[i] - arr[j]);
        }
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