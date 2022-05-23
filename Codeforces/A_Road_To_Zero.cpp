#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int x, y, a, b;
    cin>>x>>y>>a>>b;
    b = min(b, a * 2);
    int ans = 0;
    if(x > y) swap(x, y);
    ans += x * b + (y - x) * a;
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