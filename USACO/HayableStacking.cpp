#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))

void solve(){
    //code goes here
    int n, m;
    cin>>n>>m;
    vector<int> difference(n + 2);
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin>>a>>b;
        difference[a]++;
        difference[b+1]--;
    }
    vector<int> prefix(n+1);
    prefix[1] = difference[1];
    for(int i = 2; i < n; i++) {
        prefix[i] = prefix[i-1] + difference[i];
    }
    sort(prefix.begin(), prefix.end());
    cout<<prefix[n/2]<<endl;
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