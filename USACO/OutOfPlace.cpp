#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define end "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    vector<int> v(n);
    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin>>v[i];
        cin>>s[i];
    }
    sort(s.begin(), s.end());
    int ans = 0;
    for(int i = 0; i< n; i++){
        if(v[i] != s[i] ) ans++;
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