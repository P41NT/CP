#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n, k;
    cin>>n>>k;
    map<string, string> preferences;
    for(int i = 0; i < k; i++){
        string a, b;
        cin>>a>>b;
        if(a.size() <= b.size()){
            preferences.insert({a, a});
        }
        else{
            preferences.insert({a, b});
        }
    }
    while(n--){
        string c;
        cin>>c;
        cout<<preferences[c]<<" ";
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