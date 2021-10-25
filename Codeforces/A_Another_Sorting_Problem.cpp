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
    int n, m;
    cin>>n>>m;
    vector<pair<string, int>> arr(n);
    for(int i = 0; i < n; i++){
        string a;
        cin>>a;
        for(int j = 1; j < m; j+= 2){
            a[j] = 'A' + ('Z' - a[j]);
        }
        arr[i] = {a, i};
    }
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++) {
        cout<<arr[i].second + 1<<" ";
    }
    cout<<endl;
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