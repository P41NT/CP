#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    string s;
    string t;
    string ans = "";
    cin>>s>>t;
    for(int i = 0; i < s.size(); i++){
        ans += s[i];
        if(ans.size() >= t.size()){
            if(ans.substr(ans.size() - t.size(), ans.size() - 1) == t){
                ans.erase(ans.size() - t.size(), t.size());
            }
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