#include <bits/stdc++.h>

using namespace std;

//#define int long long int

void solve(){
    int n;
    cin>>n;
    vector<int> position(2 * n + 5);
    int temp;
    for(int i = 0; i < n; i++){
        cin>>temp; 
        position[temp] = i;
    }
    for(int i = 0;i < n; i++){
        cin>>temp;
        position[temp] = i;
    }
    int l = n;
    int ans = 2 * n;
    for(int i = 2 * n; i >= 1; i--){
        if(i%2 == 1) ans = min(ans, position[i] + l);
        else l = min(l, position[i]);
    }
    cout<<ans<<endl;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}
