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
    int n, k;
    cin>>n>>k;
    vector<int> arr(k);
    for(int i = 0; i < k; i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end(), greater<int>());
    int curr = 0;
    int ans = 0;
    for(int i = 0; i < k;i++){
        curr += (n - arr[i]);
        if(curr < n) ans ++;
    }
    cout<<ans<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    // t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}