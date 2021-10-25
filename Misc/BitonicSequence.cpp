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
    int n;
    cin>>n;
    vector<int> arr(n + 1);
    int total = 0;
    for(int i = 1; i < n + 1; i++){
        cin>>arr[i];
    }
    vector<int> lis(n + 1, 1), lds(n + 1, 1);
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            if(arr[i] > arr[j]){
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    for(int i = n - 1; i >= 1; i--){
        for(int j = n; j > i; j--){
            if(arr[i] > arr[j]){
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    int ans = 0; 
    for(int i = 1; i <= n; i++){
        ans = max(ans, lis[i] + lds[i]);
    }
    cout<<n + 1 - ans<<endl;
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