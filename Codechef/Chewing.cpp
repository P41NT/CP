#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define forj(i, k, j) for(int i = k; i <= j; i++)

void solve(){
    //code goes here
    int n, k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] >= k) break;
        int j = upper_bound(arr.begin(), arr.end(), k - arr[i] -1) - arr.begin();
        if(j != n && j > i)
            ans += j - i - 1;
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