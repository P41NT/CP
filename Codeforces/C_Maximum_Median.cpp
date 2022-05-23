#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))
#define forj(i, j) for(int i = 0; i < j; i++) 
#define ford(i, j) for(int i = j; i >= 0; i--)
#define loop(i, l, j, h) for(int i = l; i <= j; h)

int binary_search(int low, int high, function<bool(int)> test){
    low--;
    while(low < high){
        // int mid = low + (high - low + 1) / 2;
        int mid = (low + high + 1)/2;
        if(test(mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return low;
}

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<int> v(n);
    forj(i, n){
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    cout<<binary_search(1, 2e9, [&] (int x){
        int operations = 0;
        for(int i = (n-1)/2; i < n; i++){
            operations += max(0ll, x - v[i]);
        }
        return operations <= m;
    })<<endl;
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