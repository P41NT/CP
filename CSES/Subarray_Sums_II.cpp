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
    //code goes here
    int n, x;
    cin>>n>>x;
    vector<int> inp(n + 1);
    vector<int> prefix(n + 1);
    map<int, int> m;
    for(int i = 1; i <= n; i++){
        cin>>inp[i];
    }
    for(int i = 1; i <= n; i++){
        prefix[i] = prefix[i-1] + inp[i];
        // cout<<prefix[i]<<" ";
    }
    // cout<<endl;
    int ans = 0;
    for(int i = 0; i <= n;i++){
        m[prefix[i]]++;
        // cout<<prefix[i]<<" ";
        if(m.count(prefix[i] - x))
            ans += m[prefix[i] - x];
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