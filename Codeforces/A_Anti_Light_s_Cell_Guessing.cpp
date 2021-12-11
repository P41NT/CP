#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    int a, b;
    cin>>a>>b;
    if(a == 1 && b == 1) cout<<0<<endl;
    else if(min(a, b) == 1) cout<<1<<endl;
    else cout<<2<<endl;
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