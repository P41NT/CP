#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)

void solve(){
    //code goes here
    int n, x;
    cin>>n>>x;
    vector<int> arr(n + 1);
    for(int i = 1; i <= n; i++){
        cin>>arr[i];
    }
    vector<int> dupe = arr;
    sort(dupe.begin(), dupe.end());
    bool ok = true;
    for(int i = n - x + 1; i <= x; i++){
        if(arr[i] != dupe[i]){
            ok = false;
            break;
        }
    }
    if(ok) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //================================================================
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    //================================================================

    return 0;
}