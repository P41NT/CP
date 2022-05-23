#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl "\n"

void solve(){
    //code goes here
    string s;
    cin>>s;
    if((s[s.size() -1 ] - '0') % 2 == 0) cout<<"0"<<endl;
    else if((s[0] - '0') % 2 == 0) cout<<"1"<<endl;
    else {
        bool flag = false;
        for(char c : s){
            if((c - '0') % 2 == 0) {
                flag = true;
                cout<<2<<endl;
                break;
            }
        }
        if(!flag) cout<<-1<<endl;
    }
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