#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define end "\n"
#define vector2d(x, y, r) vector<vector<int>>(x, vector<int>(y, r));
#define vector3d(x, y, z, r) vector<vector<vector<int>>>(x, vector<vector<int>>(y, vector<int>(z, r)))

void solve(){
    int n;
    cin>>n;
    vector<int> prefix(n + 1);
    prefix[0] = 0;
    for(int i = 1; i <= n; i++){
        int temp; cin>>temp;
        prefix[i] = (prefix[i-1] + temp)%7;
    }
    map<int, int> ma;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(!ma.count(prefix[i])) ma.insert({prefix[i], i});
        else {
            ans = max(i - ma[prefix[i]], ans);
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