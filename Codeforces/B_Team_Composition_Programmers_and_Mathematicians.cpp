#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int a, b;
    cin>>a>>b;
    int expected = (a + b)/ 4;
    int minj = min(a, b);
    cout<<min(minj, expected)<<endl;
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