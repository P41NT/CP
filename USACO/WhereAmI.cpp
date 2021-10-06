#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    int n;
    cin>>n;
    string str;
    cin>>str;
    string a;
    for(int k = 1; k <= n; k++){
        bool flag = true;
        set<string> se;
        for(int j = 0; j < n - k + 1; j++){
            string curr = str.substr(j, k);
            if(se.count(curr)){
                flag = false;
                break;
            }
            se.insert(curr);
        }
        if(flag){
            cout<<k<<endl;
            break;
        }
    }
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